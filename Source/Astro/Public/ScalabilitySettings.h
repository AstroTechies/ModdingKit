#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlatformScalability.h"
#include "ScalabilitySettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class ASTRO_API UScalabilitySettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInstancedDecoratorLODDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDecoratorLODDistance;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlatformScalability PCSettings;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlatformScalability XboxOneSettings;
    
    UScalabilitySettings();

};

