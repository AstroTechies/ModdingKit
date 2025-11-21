#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ToggleComponentProperties.generated.h"

USTRUCT(BlueprintType)
struct FToggleComponentProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionProfileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECollisionEnabled::Type> CollisionEnabledType;
    
    ASTRO_API FToggleComponentProperties();
};

