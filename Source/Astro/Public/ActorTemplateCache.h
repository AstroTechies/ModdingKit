#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorTemplateCache.generated.h"

class AActor;
class UWorld;

USTRUCT(BlueprintType)
struct FActorTemplateCache {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AActor>, AActor*> ActorTemplateCache;
    
public:
    ASTRO_API FActorTemplateCache();
};

