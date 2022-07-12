#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "AstroFoliageActor.generated.h"

class UAstroFoliageType;

UCLASS(MinimalAPI, NotPlaceable)
class AAstroFoliageActor : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<UAstroFoliageType*> FoliageTypes;
    
public:
    AAstroFoliageActor();
};

