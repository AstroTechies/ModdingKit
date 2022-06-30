#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ResearchPointGrantItem.generated.h"

class UActorResearchPointGrantComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AResearchPointGrantItem : public APhysicalItem
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, VisibleAnywhere)
    UActorResearchPointGrantComponent *ResearchPointGrantComponent;

public:
    AResearchPointGrantItem();

protected:
    UFUNCTION()
    void OnUsed();
};
