#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorTemplateCache.generated.h"

class UWorld;
class AActor;

USTRUCT(BlueprintType)
struct FActorTemplateCache {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    UWorld* World;
    
    UPROPERTY()
    TMap<TSubclassOf<AActor>, AActor*> ActorTemplateCache;
    
public:
    ASTRO_API FActorTemplateCache();
};

