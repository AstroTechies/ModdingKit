#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExplodableNonPhysicalItemComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UExplodableNonPhysicalItemComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToolMoveTier;
    
    UExplodableNonPhysicalItemComponent();
};

