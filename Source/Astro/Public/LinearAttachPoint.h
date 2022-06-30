#pragma once
#include "CoreMinimal.h"
#include "LinearAttachPoint.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FLinearAttachPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* LineStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* LineEnd;
    
    ASTRO_API FLinearAttachPoint();
};

