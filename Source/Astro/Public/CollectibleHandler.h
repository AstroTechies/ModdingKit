#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CollectibleSimItem.h"
#include "Templates/SubclassOf.h"
#include "CollectibleHandler.generated.h"

class AActor;

UCLASS(Blueprintable)
class UCollectibleHandler : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* RenderActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCollectibleSimItem> SimItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> SimFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FCollectibleSimItem> RetireQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AActor>, AActor*> CachedActors;
    
    UCollectibleHandler();

};

