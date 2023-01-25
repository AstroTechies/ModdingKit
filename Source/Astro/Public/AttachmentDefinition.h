#pragma once
#include "CoreMinimal.h"
#include "ViewTargetBlendParams.h"
#include "AttachmentDefinition.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FAttachmentDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachmentLocationCompName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DetachmentLocationCompName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FViewTargetBlendParams ViewTargetBlendParamsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseViewTargetBlendParamsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* AttachmentLocationComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* DetachmentLocationComp;
    
    ASTRO_API FAttachmentDefinition();
};

