#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WindResistance.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWindResistance : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SurfaceArea;

    UWindResistance();
};
