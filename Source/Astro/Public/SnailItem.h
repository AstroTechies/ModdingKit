#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "InputCoreTypes.h"
#include "ECrackableActorNetworkingPolicy.h"
#include "EEmoteType.h"
#include "ESnailBehaviorTriggerType.h"
#include "ESnailFoodType.h"
#include "OnSnailFedChangedDelegate.h"
#include "PhysicalItem.h"
#include "SlotReference.h"
#include "SnailFoodData.h"
#include "Templates/SubclassOf.h"
#include "SnailItem.generated.h"

class AActor;
class APlayController;
class ASnailCrackableActor;
class UAdaptiveTickComponent;
class UChildActorComponent;
class UCrackableActorComponent;
class UItemList;
class UItemType;
class UPlanetEffect;
class UPrimitiveComponent;
class USkeletalMeshComponent;
class USlotsComponent;
class USnailBehaviorTable;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ASnailItem : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FedDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESnailFoodType, FSnailFoodData> SnailFoodDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    ESnailFoodType CurrentFoodType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AdjustedFedDuration;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSnailFedChanged OnSnailFedChanged;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TerrariumChildActorComponentRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UChildActorComponent* ChildActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* ChildCrackableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* ChildSnailSkeleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ChildTerrariumMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RootTerrariumMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USlotsComponent* ChildSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASnailCrackableActor* TerrariumChildActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_OnSnailIsInteractableChanged, meta=(AllowPrivateAccess=true))
    uint8 bSnailIsInteractable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference FoodSlotRef;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FoodSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USnailBehaviorTable* BehaviorTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 bIsFed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float remainingBuffTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlappingPlayers;
    
public:
    ASnailItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateSnailBuffDuration(float DeltaSeconds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupChildActorRefsBP();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSnailFedEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSnailFed(ESnailFoodType foodType);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnSnailCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_OnSnailIsInteractableChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerEmotePlayed(EEmoteType EmoteType, APlayController* Player);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnItemPlacedInFoodSlot(APhysicalItem* Item);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnEffectRelevanceChanged(bool IsInRelevancy);
    
    UFUNCTION(BlueprintCallable)
    void OnChildActorInputActionUse();
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastTriggerSnailBehavior(ESnailBehaviorTriggerType Trigger, bool bLooping);
    
private:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSnailFedUpdate(bool bNewFedState, ESnailFoodType newFoodType);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFed();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandlePickedUpInWorld(bool bPhysicalMovement);
    
    UFUNCTION(BlueprintCallable)
    void HandleOnSpawnedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnSetItemInFoodSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void HandleChildActorClicked(AActor* Actor, FKey Key);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UItemList> GetValidFoodItemsFromFoodType(ESnailFoodType foodType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ESnailFoodType GetFoodTypeFromItemType(const TSubclassOf<UItemType> foodItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElapsedBuffTime();
    
private:
    UFUNCTION(BlueprintCallable)
    void EnableLightbar();
    
    UFUNCTION(BlueprintCallable)
    void DisableLightbar();
    
    UFUNCTION(BlueprintCallable)
    void ChangeChildNetworkingPolicy(ECrackableActorNetworkingPolicy newPolicy);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetSnailInteractable(bool bIsInteractable);
    
};

