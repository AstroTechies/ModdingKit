#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroMessageOfTheDayManager.generated.h"

class UMessageOfTheDay;

UCLASS(Blueprintable)
class MESSAGEOFTHEDAY_API UAstroMessageOfTheDayManager : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroMessageOfTheDayManager();
    UFUNCTION(BlueprintCallable)
    static void SetDefaultMessage(UMessageOfTheDay* Message);
    
    UFUNCTION(BlueprintCallable)
    static UMessageOfTheDay* GetForCurrentCulture();
    
};

