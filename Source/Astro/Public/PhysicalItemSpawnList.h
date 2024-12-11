#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhysicalItemSpecifier.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItemSpawnList.generated.h"

class APhysicalItem;
class UPhysicalItemSpawnList;

UCLASS(Blueprintable)
class ASTRO_API UPhysicalItemSpawnList : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPhysicalItemSpecifier> ActorTypes;
    
    UPhysicalItemSpawnList();

    UFUNCTION(BlueprintCallable)
    TSubclassOf<APhysicalItem> PickActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPhysicalItemSpawnList* PhysicalItemSpawnListDefault(TSubclassOf<UPhysicalItemSpawnList> Type);
    
};

