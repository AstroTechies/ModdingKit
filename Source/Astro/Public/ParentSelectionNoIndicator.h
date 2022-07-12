#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ParentSelectionNoIndicator.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UParentSelectionNoIndicator : public UActorComponent {
    GENERATED_BODY()
public:
    UParentSelectionNoIndicator();
};

