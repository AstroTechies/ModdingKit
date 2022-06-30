#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardLoadedDelegate.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "LoadedCard.h"
#include "AstropediaAssetManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstropediaAssetManager : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FCardLoaded OnCardLoaded;

    UAstropediaAssetManager();
    UFUNCTION(BlueprintCallable)
    bool SetCardShownAndLoadAsync(EAstroGameMenuTutoriaSlideCardKey cardKey);

    UFUNCTION(BlueprintCallable)
    void SetCardHidden(EAstroGameMenuTutoriaSlideCardKey cardKey);

private:
    UFUNCTION()
    void HandleCardLoaded(FLoadedCard LoadedCard);
};
