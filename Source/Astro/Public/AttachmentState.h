#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "EEnterExitMovementMethod.h"
#include "ViewTargetBlendParams.h"
#include "AttachmentState.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FAttachmentState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExiting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOwnerIsViewTargetWhileAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnterExitMovementMethod MovementMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FViewTargetBlendParams ViewTargetBlendParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize10 ExitRelativeOffset;
    
    ASTRO_API FAttachmentState();
};

