#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ResearchModule.generated.h"

class UActorResearchComponent;
class UAdaptiveTickComponent;
class UPowerComponent;

UCLASS(Blueprintable)
class ASTRO_API AResearchModule : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UActorResearchComponent* ActorResearchComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTickComponent;
    
public:
    AResearchModule(const FObjectInitializer& ObjectInitializer);

};

