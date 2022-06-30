#pragma once
#include "CoreMinimal.h"
#include "GlobalSurfaceActorPlacementModifier.h"
#include "UObject/NoExportTypes.h"
#include "GlobalStartingPointPlacementModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UGlobalStartingPointPlacementModifier : public UGlobalSurfaceActorPlacementModifier
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FVector PreferencePoint;

    UGlobalStartingPointPlacementModifier();
};
