#pragma once
#include "CoreMinimal.h"
#include "ERepackagingTargetState.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "Repackager.generated.h"

class AActor;
class UAstroAction;
class UAstroActionComponent;
class UAstroRepackAction;
class UItemComponent;
class UItemType;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ARepackager : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APhysicalItem> PreviousRepackagingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APhysicalItem> RepackagingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepackagingTargetStateChanged, meta=(AllowPrivateAccess=true))
    ERepackagingTargetState TargetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroRepackAction> RepackActionType;
    
public:
    ARepackager(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void UpdateRepackagingTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepackagingTargetStateChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRepackageActionFinishedAuthority(UAstroAction* repackageAction);
    
    UFUNCTION(BlueprintCallable)
    void OnAttachedItemStoredItemTypeChanged(UItemComponent* changedItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void InitiateRepackaging();
    
    UFUNCTION(BlueprintCallable)
    void HandleRepackagingTargetEndPlay(AActor* Actor);
    
};

