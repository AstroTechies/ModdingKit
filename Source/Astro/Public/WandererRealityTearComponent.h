#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "WandererRealityTearComponent.generated.h"

class AAstroPlayerController;
class APlayerController;
class UItemType;
class UWandererPhotoWidget;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UWandererRealityTearComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DestroyTimeoutSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UWandererPhotoWidget> PhotoWidgetClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SceneCaptureComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeformRadius;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FComponentReference> DeformLocationComponents;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ActivatingPlayer, meta=(AllowPrivateAccess=true))
    uint64 ActivatingPlayerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> UnlockItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ProbeItemType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnActivatingPlayerSet;
    
public:
    UWandererRealityTearComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WasActivatedByPlayer(const APlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable)
    void TakePhoto(APlayerController* inputPlayer);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ActivatingPlayer();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void MarkActivated_AuthorityOnly();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DisplayPhotoWidget_Multicast(AAstroPlayerController* inputPlayer);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DisplayPhotoWidget(APlayerController* inputPlayer);
    
};

