#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ParentSelectionNoIndicator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UParentSelectionNoIndicator : public UActorComponent {
    GENERATED_BODY()
public:
    UParentSelectionNoIndicator();
};

