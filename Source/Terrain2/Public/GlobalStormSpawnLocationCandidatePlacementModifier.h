#pragma once
#include "CoreMinimal.h"
#include "GlobalSurfaceActorPlacementModifier.h"
#include "GlobalStormSpawnLocationCandidatePlacementModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UGlobalStormSpawnLocationCandidatePlacementModifier : public UGlobalSurfaceActorPlacementModifier {
    GENERATED_BODY()
public:
    UGlobalStormSpawnLocationCandidatePlacementModifier();

};

