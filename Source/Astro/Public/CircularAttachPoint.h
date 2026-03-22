#pragma once
#include "CoreMinimal.h"
#include "CircularAttachPoint.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FCircularAttachPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CircleCenter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    ASTRO_API FCircularAttachPoint();
};

