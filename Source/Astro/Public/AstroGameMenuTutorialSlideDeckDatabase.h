#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "AstroGameMenuTutorialSlide.h"
#include "AstroGameMenuTutorialSlideDeck.h"
#include "AstroGameMenuTutorialSlideDeckDatabase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstroGameMenuTutorialSlideDeckDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TMap<EAstroGameMenuTutoriaSlideCardKey, FAstroGameMenuTutorialSlide> TutorialSlideCards;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TMap<EAstroGameMenuTutorialSlideDeckKey, FAstroGameMenuTutorialSlideDeck> TutorialSlideDecks;

    UAstroGameMenuTutorialSlideDeckDatabase();
};
