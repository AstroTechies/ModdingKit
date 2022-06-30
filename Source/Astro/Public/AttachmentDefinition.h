#pragma once
#include "CoreMinimal.h"
#include "ViewTargetBlendParams.h"
#include "AttachmentDefinition.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FAttachmentDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FName AttachmentLocationCompName;
    
    UPROPERTY(EditDefaultsOnly)
    FName DetachmentLocationCompName;
    
    UPROPERTY(EditDefaultsOnly)
    FViewTargetBlendParams ViewTargetBlendParamsOverride;
    
    UPROPERTY(EditDefaultsOnly)
    bool UseViewTargetBlendParamsOverride;
    
    UPROPERTY(Export)
    USceneComponent* AttachmentLocationComp;
    
    UPROPERTY(Export)
    USceneComponent* DetachmentLocationComp;
    
    ASTRO_API FAttachmentDefinition();
};

