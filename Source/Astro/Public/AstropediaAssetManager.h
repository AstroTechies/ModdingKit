#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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
    UFUNCTION()
    void HandleCardLoaded(FLoadedCard LoadedCard);
    
};

