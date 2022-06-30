#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AstroFoliageActor.generated.h"

class UAstroFoliageType;

UCLASS(Blueprintable, MinimalAPI, NotPlaceable)
class AAstroFoliageActor : public AActor
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<UAstroFoliageType *> FoliageTypes;

public:
    AAstroFoliageActor();
};
