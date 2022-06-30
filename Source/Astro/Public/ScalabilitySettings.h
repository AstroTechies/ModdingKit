#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "PlatformScalability.h"
#include "ScalabilitySettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config = Game)
class ASTRO_API UScalabilitySettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(Config, EditAnywhere)
    float MinInstancedDecoratorLODDistance;

    UPROPERTY(Config, EditAnywhere)
    float MinDecoratorLODDistance;

    UPROPERTY(Config, EditAnywhere)
    FPlatformScalability PCSettings;

    UPROPERTY(Config, EditAnywhere)
    FPlatformScalability XboxOneSettings;

    UScalabilitySettings();
};
