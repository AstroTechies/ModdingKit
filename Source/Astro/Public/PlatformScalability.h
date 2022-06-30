#pragma once
#include "CoreMinimal.h"
#include "EScalabilityLevel.h"
#include "PlatformScalability.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FPlatformScalability {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float DecoratorLODDistanceScale;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> ViewDistanceQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> TextureQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> ShadowQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> EffectsQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> FoliageQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> AntiAliasingQuality;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EScalabilityLevel> PostProcessQuality;
    
    FPlatformScalability();
};

