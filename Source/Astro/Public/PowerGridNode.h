#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PowerGridNode.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPowerGridNode : public UActorComponent {
    GENERATED_BODY()
public:
    UPowerGridNode(const FObjectInitializer& ObjectInitializer);

};

