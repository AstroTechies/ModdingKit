#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "ERepackagingTargetState.h"
#include "Repackager.generated.h"

class UAstroActionComponent;
class UAstroRepackAction;
class UAstroAction;
class AActor;

UCLASS(Abstract, Blueprintable)
class ASTRO_API ARepackager : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    UPROPERTY(EditAnywhere, Transient)
    TWeakObjectPtr<APhysicalItem> RepackagingTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRepackagingTargetStateChanged, meta=(AllowPrivateAccess=true))
    ERepackagingTargetState TargetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroRepackAction> RepackActionType;
    
public:
    ARepackager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void UpdateRepackagingTarget();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnRepackagingTargetStateChanged();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnRepackageActionFinishedAuthority(UAstroAction* repackageAction);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void InitiateRepackaging();
    
    UFUNCTION()
    void HandleRepackagingTargetEndPlay(AActor* Actor);
    
};

