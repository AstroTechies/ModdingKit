#pragma once
#include "CoreMinimal.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "AstroGameMenuTutorialSlideDeck.generated.h"

USTRUCT(BlueprintType)
struct FAstroGameMenuTutorialSlideDeck {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EAstroGameMenuTutoriaSlideCardKey> SlidesInDeck;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DeckDescriptiveName;
    
    ASTRO_API FAstroGameMenuTutorialSlideDeck();
};

