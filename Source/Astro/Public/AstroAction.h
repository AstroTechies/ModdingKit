#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=GameplayTasks -ObjectName=GameplayTaskOwnerInterface -FallbackName=GameplayTaskOwnerInterface
#include "GameplayTaskOwnerInterface.h"
#include "AstroActionContext.h"
#include "AstroActionIdentifier.h"
#include "EAstroActionState.h"
#include "OnActionEndedDelegate.h"
#include "AstroAction.generated.h"

class UGameplayTask;

UCLASS(Abstract, Blueprintable)
class ASTRO_API UAstroAction : public UObject, public IGameplayTaskOwnerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActionEnded OnActionEnded;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RequiredResources;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bInterruptedBySamePriority: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroActionIdentifier Identifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroActionState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroActionContext Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UGameplayTask*> ActiveTasks;
    
public:
    UAstroAction();
    
    // Fix for true pure virtual functions not being implemented
};

