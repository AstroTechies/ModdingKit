#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "ResearchPointGrantItem.generated.h"

class UActorResearchPointGrantComponent;

UCLASS(Blueprintable)
class ASTRO_API AResearchPointGrantItem : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorResearchPointGrantComponent* ResearchPointGrantComponent;
    
public:
    AResearchPointGrantItem();
protected:
    UFUNCTION(BlueprintCallable)
    void OnUsed();
    
};

