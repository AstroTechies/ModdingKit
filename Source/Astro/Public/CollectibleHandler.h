#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "CollectibleSimItem.h"
#include "CollectibleHandler.generated.h"

class AActor;

UCLASS(Blueprintable, Blueprintable)
class UCollectibleHandler : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    AActor *RenderActor;

    UPROPERTY(Transient)
    TArray<FCollectibleSimItem> SimItems;

    UPROPERTY(Transient)
    TArray<int32> SimFlags;

    UPROPERTY(Transient)
    TArray<FCollectibleSimItem> RetireQueue;

    UPROPERTY(Transient)
    TMap<TSubclassOf<AActor>, AActor *> CachedActors;

    UCollectibleHandler();
};
