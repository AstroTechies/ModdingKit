#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponent.h"
#include "ResearchPointGrantComponent.generated.h"

USTRUCT(BlueprintType)
struct FResearchPointGrantComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float ResearchPointsGranted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bResearchPointsHaveBeenGranted: 1;
    
    ASTRO_API FResearchPointGrantComponent();
};

