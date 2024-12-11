#pragma once
#include "CoreMinimal.h"
#include "ActorPlacementModifier.h"
#include "ActorSurfacePlacementModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UActorSurfacePlacementModifier : public UActorPlacementModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalOffsetFromSurface;
    
    UActorSurfacePlacementModifier();

};

