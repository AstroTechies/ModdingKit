#pragma once
#include "CoreMinimal.h"
#include "EMiniPlanetIdentifier.h"
#include "Templates/SubclassOf.h"
#include "MiniPlanetDefinition.generated.h"

class AMiniPlanet;
class UItemType;

USTRUCT(BlueprintType)
struct FMiniPlanetDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiniPlanetIdentifier MiniPlanetIdentifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMiniPlanet> MiniPlanetClass;
    
    ASTRO_API FMiniPlanetDefinition();
};

