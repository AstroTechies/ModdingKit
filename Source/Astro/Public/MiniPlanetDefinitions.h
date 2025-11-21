#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MiniPlanetDefinition.h"
#include "Templates/SubclassOf.h"
#include "MiniPlanetDefinitions.generated.h"

class AMiniPlanet;

UCLASS(Blueprintable)
class ASTRO_API UMiniPlanetDefinitions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMiniPlanetDefinition> MiniPlanets;
    
    UMiniPlanetDefinitions();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumMiniPlanets() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMiniPlanetIndex(const TSubclassOf<AMiniPlanet> MiniPlanetClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FMiniPlanetDefinition GetMiniPlanetDefinition(int32 Index);
    
};

