#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorSpecifier.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FActorSpecifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Weight;
    
    ASTRO_API FActorSpecifier();
};

