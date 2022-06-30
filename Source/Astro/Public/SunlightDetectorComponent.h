#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalDelegate.h"
#include "SunlightDetectorComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API USunlightDetectorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MinExposure;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *CastComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float SunExposure;

    UPROPERTY(BlueprintAssignable)
    FSignal SunlightExceededMinExposure;

    UPROPERTY(BlueprintAssignable)
    FSignal SunlightFellBelowMinExposure;

    USunlightDetectorComponent();
};
