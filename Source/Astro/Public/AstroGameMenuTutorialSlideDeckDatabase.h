#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "AstroGameMenuTutorialSlide.h"
#include "AstroGameMenuTutorialSlideDeck.h"
#include "AstroGameMenuTutorialSlideDeckDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroGameMenuTutorialSlideDeckDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroGameMenuTutoriaSlideCardKey, FAstroGameMenuTutorialSlide> TutorialSlideCards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroGameMenuTutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck> TutorialSlideDecks;
    
    UAstroGameMenuTutorialSlideDeckDatabase();
};

