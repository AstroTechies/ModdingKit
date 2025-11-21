#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AstroMessageOfTheDayManager.generated.h"

class UMarketingWidgetsData;
class UMessageOfTheDay;

UCLASS(Blueprintable)
class MESSAGEOFTHEDAY_API UAstroMessageOfTheDayManager : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroMessageOfTheDayManager();

    UFUNCTION(BlueprintCallable)
    static void SuppressMotD(const bool shouldSupress);
    
    UFUNCTION(BlueprintCallable)
    static void SetDefaultMessage(UMessageOfTheDay* Message);
    
    UFUNCTION(BlueprintCallable)
    static void ResetFullscreenMotDViewData(bool resetLatestTitleNewsData);
    
    UFUNCTION(BlueprintCallable)
    static void MarkLatestFullscreenMotDSeen();
    
    UFUNCTION(BlueprintCallable)
    static void HideFullscreenMotD();
    
    UFUNCTION(BlueprintCallable)
    static UMarketingWidgetsData* GetMarketingWidgetsForCurrentCulture();
    
    UFUNCTION(BlueprintCallable)
    static UMessageOfTheDay* GetForCurrentCulture();
    
    UFUNCTION(BlueprintCallable)
    static void DisplayFullscreenMotD(const bool bypassPreviousViewData);
    
};

