#pragma once
#include "CoreMinimal.h"
#include "InteractionTarget.generated.h"

class AActor;
class UClickableComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FInteractionTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* AttachParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    ASTRO_API FInteractionTarget();
};

