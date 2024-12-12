#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroCustomizationBPL.generated.h"

class UAstroCustomizationItem;
class UObject;

UCLASS(Blueprintable)
class ASTRO_API UAstroCustomizationBPL : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroCustomizationBPL();

    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAstroCustomizationItem* LoadCustomizationItemFromPath(UObject* WorldContextObject, const FString& ItemPath);
    
};

