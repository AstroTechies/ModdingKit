#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroMessageOfTheDayManager.generated.h"

class UMessageOfTheDay;

UCLASS(Blueprintable, BlueprintType)
class MESSAGEOFTHEDAY_API UAstroMessageOfTheDayManager : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UAstroMessageOfTheDayManager();
    UFUNCTION(BlueprintCallable)
    static void SetDefaultMessage(UMessageOfTheDay *Message);

    UFUNCTION(BlueprintCallable)
    static UMessageOfTheDay *GetForCurrentCulture();
};
