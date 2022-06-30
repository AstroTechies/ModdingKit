#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "NavpointTypeConfig.generated.h"

class UTexture;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FNavpointTypeConfig {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FLinearColor Color;
    
    UPROPERTY(EditDefaultsOnly)
    UTexture* Icon;
    
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh* IconCapMesh;
    
    UPROPERTY(EditDefaultsOnly)
    float IconScale;
    
    UPROPERTY(EditDefaultsOnly)
    FVector2D IconOffset;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 Priority;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 MaxDisplayed;
    
    ASTRO_API FNavpointTypeConfig();
};

