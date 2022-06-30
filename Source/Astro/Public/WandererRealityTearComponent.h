#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SignalDelegate.h"
#include "WandererRealityTearComponent.generated.h"

class UWandererPhotoWidget;
class APlayerController;
class UItemType;
class AAstroPlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWandererRealityTearComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    float DestroyTimeoutSeconds;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetClass;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference SceneCaptureComponent;

    UPROPERTY(EditDefaultsOnly)
    float DeformRadius;

    UPROPERTY(EditDefaultsOnly)
    TArray<FComponentReference> DeformLocationComponents;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_ActivatingPlayer)
    uint64 ActivatingPlayerID;

    UPROPERTY(SaveGame)
    TArray<FString> UnlockItems;

    UPROPERTY(SaveGame)
    TSubclassOf<UItemType> ProbeItemType;

    UPROPERTY(BlueprintAssignable)
    FSignal OnActivatingPlayerSet;

public:
    UWandererRealityTearComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintPure)
    bool WasActivatedByPlayer(const APlayerController *Player);

protected:
    UFUNCTION(BlueprintCallable)
    void TakePhoto(APlayerController *inputPlayer);

    UFUNCTION()
    void OnRep_ActivatingPlayer();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void MarkActivated_AuthorityOnly();

    UFUNCTION(NetMulticast, Reliable)
    void DisplayPhotoWidget_Multicast(AAstroPlayerController *inputPlayer);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DisplayPhotoWidget(APlayerController *inputPlayer);
};
