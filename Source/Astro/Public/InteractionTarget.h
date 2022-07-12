#pragma once
#include "CoreMinimal.h"
#include "InteractionTarget.generated.h"

class AActor;
class USceneComponent;
class UClickableComponent;

USTRUCT(BlueprintType)
struct FInteractionTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* AttachParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    ASTRO_API FInteractionTarget();
};

