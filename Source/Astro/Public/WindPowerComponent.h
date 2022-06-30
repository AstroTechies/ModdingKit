#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WindPowerComponent.generated.h"

class UPowerComponent;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWindPowerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MinExposure;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MinPowerOutput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    float MaxPowerOutput;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *CastComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float WindExposure;

    UPROPERTY(EditAnywhere)
    float CastDistance;

private:
    UPROPERTY(Export)
    UPowerComponent *PowerComponent;

public:
    UWindPowerComponent();
};
