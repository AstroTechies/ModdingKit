#pragma once
#include "CoreMinimal.h"
#include "SingleUseConsumableComponent.h"
#include "ActorResearchPointGrantComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorResearchPointGrantComponent : public USingleUseConsumableComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinPointsGranted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxPointsGranted;
    
    UActorResearchPointGrantComponent(const FObjectInitializer& ObjectInitializer);

};

