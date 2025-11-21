#pragma once
#include "CoreMinimal.h"
#include "ELRDType.h"
#include "PhysicalItem.h"
#include "LRD.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ALRD : public APhysicalItem {
    GENERATED_BODY()
public:
    ALRD(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    ELRDType GetLRDType();
    
};

