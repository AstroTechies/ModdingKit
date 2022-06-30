#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorSpecifier.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorSpecifier {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> Actor;
    
    UPROPERTY(EditAnywhere)
    float Weight;
    
    ASTRO_API FActorSpecifier();
};

