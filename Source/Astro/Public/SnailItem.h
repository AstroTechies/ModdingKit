#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ESnailFoodType.h"
#include "SnailFoodData.h"
#include "OnSnailFedChangedDelegate.h"
#include "Engine/EngineTypes.h"
#include "ECrackableActorNetworkingPolicy.h"
#include "SlotReference.h"
#include "EEmoteType.h"
#include "ESnailBehaviorTriggerType.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "SnailItem.generated.h"

class UItemList;
class ASnailCrackableActor;
class UCrackableActorComponent;
class USkeletalMeshComponent;
class UChildActorComponent;
class UStaticMeshComponent;
class USlotsComponent;
class UPlanetEffect;
class UAdaptiveTickComponent;
class USnailBehaviorTable;
class AActor;
class APlayController;
class UPrimitiveComponent;
class UItemType;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ASnailItem : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    float FedDuration;

    UPROPERTY(EditDefaultsOnly)
    TMap<ESnailFoodType, FSnailFoodData> SnailFoodDefinitions;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    ESnailFoodType CurrentFoodType;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    float AdjustedFedDuration;

    UPROPERTY(BlueprintAssignable)
    FOnSnailFedChanged OnSnailFedChanged;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference TerrariumChildActorComponentRef;

    UPROPERTY(Export, Transient)
    UChildActorComponent *ChildActorComponent;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UCrackableActorComponent *ChildCrackableComponent;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    USkeletalMeshComponent *ChildSnailSkeleton;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *ChildTerrariumMesh;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *RootTerrariumMesh;

    UPROPERTY(BlueprintReadWrite, Export, Transient, meta = (AllowPrivateAccess = true))
    USlotsComponent *ChildSlotComponent;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    ASnailCrackableActor *TerrariumChildActor;

    UPROPERTY(ReplicatedUsing = OnRep_OnSnailIsInteractableChanged)
    uint8 bSnailIsInteractable : 1;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    FSlotReference FoodSlotRef;

private:
    UPROPERTY(Export, VisibleAnywhere)
    UPlanetEffect *PlanetEffect;

    UPROPERTY(Export, VisibleAnywhere)
    UAdaptiveTickComponent *AdaptiveTickComponent;

    UPROPERTY(EditDefaultsOnly)
    FName FoodSlotName;

    UPROPERTY(EditDefaultsOnly)
    USnailBehaviorTable *BehaviorTable;

    UPROPERTY(Replicated)
    uint8 bIsFed : 1;

    UPROPERTY(Replicated, SaveGame)
    float remainingBuffTime;

    UPROPERTY()
    TArray<AActor *> OverlappingPlayers;

public:
    ASnailItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void UpdateSnailBuffDuration(float DeltaSeconds);

    UFUNCTION(BlueprintImplementableEvent)
    void SetupChildActorRefsBP();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSnailFedEnd();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSnailFed(ESnailFoodType foodType);

private:
    UFUNCTION()
    void OnSnailCrackedChanged(UCrackableActorComponent *CrackableActorComponent, bool cracked);

    UFUNCTION()
    void OnRep_OnSnailIsInteractableChanged();

    UFUNCTION()
    void OnPlayerEmotePlayed(EEmoteType EmoteType, APlayController *Player);

protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnItemPlacedInFoodSlot(APhysicalItem *Item);

private:
    UFUNCTION()
    void OnEffectRelevanceChanged(bool IsInRelevancy);

    UFUNCTION()
    void OnChildActorInputActionUse();

public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastTriggerSnailBehavior(ESnailBehaviorTriggerType Trigger, bool bLooping);

private:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSnailFedUpdate(bool bNewFedState, ESnailFoodType newFoodType);

public:
    UFUNCTION(BlueprintPure)
    bool IsFed();

private:
    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);

    UFUNCTION()
    void HandlePlacedInSlot();

    UFUNCTION()
    void HandlePickedUpInWorld(bool bPhysicalMovement);

    UFUNCTION()
    void HandleOnSpawnedInSlot();

    UFUNCTION()
    void HandleOnSetItemInFoodSlot(APhysicalItem *Item);

    UFUNCTION()
    void HandleDroppedInWorld(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

    UFUNCTION()
    void HandleChildActorClicked(AActor *Actor, FKey Key);

public:
    UFUNCTION(BlueprintPure)
    TSubclassOf<UItemList> GetValidFoodItemsFromFoodType(ESnailFoodType foodType);

    UFUNCTION(BlueprintPure)
    ESnailFoodType GetFoodTypeFromItemType(const TSubclassOf<UItemType> foodItemType);

    UFUNCTION(BlueprintPure)
    float GetElapsedBuffTime();

private:
    UFUNCTION()
    void ChangeChildNetworkingPolicy(ECrackableActorNetworkingPolicy newPolicy);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetSnailInteractable(bool bIsInteractable);
};
