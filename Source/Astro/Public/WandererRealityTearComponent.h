#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "WandererRealityTearComponent.generated.h"

class UWandererPhotoWidget;
class UItemType;
class APlayerController;
class AAstroPlayerController;

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
    FComponentReference DeformLocationComponents;
    
    UPROPERTY(EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ActivatingPlayer)
    uint64 ActivatingPlayerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FString> UnlockItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ProbeItemType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnActivatingPlayerSet;
    
public:
    UWandererRealityTearComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintPure)
    bool WasActivatedByPlayer(const APlayerController* Player);
    
protected:
    UFUNCTION(BlueprintCallable)
    void TakePhoto(APlayerController* inputPlayer);
    
    UFUNCTION()
    void OnRep_ActivatingPlayer();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void MarkActivated_AuthorityOnly();
    
    UFUNCTION(NetMulticast, Reliable)
    void DisplayPhotoWidget_Multicast(AAstroPlayerController* inputPlayer);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void DisplayPhotoWidget(APlayerController* inputPlayer);
    
};

