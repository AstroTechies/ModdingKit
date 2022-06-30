#pragma once
#include "CoreMinimal.h"
#include "OnActionEndedDelegate.h"
#include "UObject/Object.h"
#include "AstroActionContext.h"
#include "GameplayTaskOwnerInterface.h"
#include "EAstroActionState.h"
#include "AstroActionIdentifier.h"
#include "AstroAction.generated.h"

class UGameplayTask;

UCLASS(Blueprintable, Abstract, BlueprintType)
class ASTRO_API UAstroAction : public UObject, public IGameplayTaskOwnerInterface
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnActionEnded OnActionEnded;

protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 RequiredResources;

    UPROPERTY(EditDefaultsOnly)
    uint8 Priority;

    UPROPERTY(EditDefaultsOnly)
    uint8 bInterruptedBySamePriority : 1;

    UPROPERTY()
    FAstroActionIdentifier Identifier;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    EAstroActionState State;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FAstroActionContext Context;

    UPROPERTY(Transient)
    TArray<UGameplayTask *> ActiveTasks;

public:
    UAstroAction();

    // Fix for true pure virtual functions not being implemented
};
