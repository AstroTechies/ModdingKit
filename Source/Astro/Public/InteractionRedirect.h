#pragma once
#include "CoreMinimal.h"
#include "InteractionRedirect.generated.h"

class AActor;
class USceneComponent;

USTRUCT(BlueprintType)
struct FInteractionRedirect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* NewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* PivotComponent;
    
    ASTRO_API FInteractionRedirect();
};

