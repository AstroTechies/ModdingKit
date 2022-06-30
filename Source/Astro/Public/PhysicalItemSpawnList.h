#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "PhysicalItemSpecifier.h"
#include "PhysicalItemSpawnList.generated.h"

class APhysicalItem;
class UPhysicalItemSpawnList;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UPhysicalItemSpawnList : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FPhysicalItemSpecifier> ActorTypes;

    UPhysicalItemSpawnList();
    UFUNCTION(BlueprintCallable)
    TSubclassOf<APhysicalItem> PickActor();

    UFUNCTION(BlueprintPure)
    static UPhysicalItemSpawnList *PhysicalItemSpawnListDefault(TSubclassOf<UPhysicalItemSpawnList> Type);
};
