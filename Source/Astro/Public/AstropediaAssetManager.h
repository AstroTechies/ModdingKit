#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CardLoadedDelegate.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "LoadedCard.h"
#include "AstropediaAssetManager.generated.h"

UCLASS(Blueprintable)
class UAstropediaAssetManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCardLoaded OnCardLoaded;
    
    UAstropediaAssetManager();

    UFUNCTION(BlueprintCallable)
    bool SetCardShownAndLoadAsync(EAstroGameMenuTutoriaSlideCardKey cardKey);
    
    UFUNCTION(BlueprintCallable)
    void SetCardHidden(EAstroGameMenuTutoriaSlideCardKey cardKey);
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleCardLoaded(FLoadedCard LoadedCard);
    
};

