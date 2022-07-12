#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ECrackableActorNetworkingPolicy.h"
#include "ESnailFoodType.h"
#include "SlotReference.h"
#include "SnailFoodData.h"
#include "OnSnailFedChangedDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "ESnailBehaviorTriggerType.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "SnailItem.generated.h"

class USlotsComponent;
class UPrimitiveComponent;
class UChildActorComponent;
class UCrackableActorComponent;
class USkeletalMeshComponent;
class UStaticMeshComponent;
class UItemType;
class ASnailCrackableActor;
class UPlanetEffect;
class UAdaptiveTickComponent;
class USnailBehaviorTable;
class AActor;
class UItemList;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UChildActorComponent* ChildActorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UCrackableActorComponent* ChildCrackableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* ChildSnailSkeleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ChildTerrariumMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* RootTerrariumMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USlotsComponent* ChildSlotComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASnailCrackableActor* TerrariumChildActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_OnSnailIsInteractableChanged, meta=(AllowPrivateAccess=true))
    uint8 bSnailIsInteractable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference FoodSlotRef;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
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
    ASnailItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    void OnSnailCrackedChanged(UCrackableActorComponent* CrackableActorComponent, bool cracked);
    
    UFUNCTION()
    void OnRep_OnSnailIsInteractableChanged();
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnItemPlacedInFoodSlot(APhysicalItem* Item);
    
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
    void HandleOnSetItemInFoodSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void HandleDroppedInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION()
    void HandleChildActorClicked(AActor* Actor, FKey Key);
    
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

