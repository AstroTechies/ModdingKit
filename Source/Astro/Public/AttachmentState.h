#pragma once
#include "CoreMinimal.h"
#include "ViewTargetBlendParams.h"
#include "EEnterExitMovementMethod.h"
#include "Engine/NetSerialization.h"
#include "AttachmentState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FAttachmentState {
    GENERATED_BODY()
public:
    UPROPERTY()
    AActor* Actor;
    
    UPROPERTY()
    bool bExiting;
    
    UPROPERTY()
    bool bOwnerIsViewTargetWhileAttached;
    
    UPROPERTY()
    EEnterExitMovementMethod MovementMethod;
    
    UPROPERTY()
    FViewTargetBlendParams ViewTargetBlendParams;
    
    UPROPERTY()
    FVector_NetQuantize10 ExitRelativeOffset;
    
    ASTRO_API FAttachmentState();
};

