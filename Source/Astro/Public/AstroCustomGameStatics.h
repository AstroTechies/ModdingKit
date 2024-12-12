#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroCustomGameStatics.generated.h"

class AAstroCustomGameManager;
class AAstroGameState;
class UObject;
class USlotsComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroCustomGameStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroCustomGameStatics();

    UFUNCTION(BlueprintCallable)
    static void SpawnStartingItems(USlotsComponent* backpackSlotsComponent, USlotsComponent* deformToolSlotsComponent, AAstroGameState* GameState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroCustomGameManager* GetCustomGameManager(const UObject* WorldContextObject);
    
};

