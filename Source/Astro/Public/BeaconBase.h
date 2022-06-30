#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "BeaconBase.generated.h"

class USceneComponent;

UCLASS(Blueprintable, Abstract)
class ABeaconBase : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(Export, Transient)
    USceneComponent *HoverPointComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PlanetDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MinViewDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MaxViewDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BeaconHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PlumbLineOffset;

private:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference HoverPointReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference IconComponentReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference IndicatorLineComponentReference;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference IconRootReference;

    UPROPERTY(Export, Transient)
    USceneComponent *IconComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *IndicatorLineComponent;

    UPROPERTY(Export, Transient)
    USceneComponent *IconRootComponent;

    UPROPERTY(Export, Transient)
    TArray<USceneComponent *> IconChildren;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bBeaconVisible : 1;

    ABeaconBase();
};
