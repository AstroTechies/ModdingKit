#pragma once
#include "CoreMinimal.h"
#include "GlobalSurfaceActorPlacementModifier.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GlobalStartingPointPlacementModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class TERRAIN2_API UGlobalStartingPointPlacementModifier : public UGlobalSurfaceActorPlacementModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PreferencePoint;
    
    UGlobalStartingPointPlacementModifier();
};

