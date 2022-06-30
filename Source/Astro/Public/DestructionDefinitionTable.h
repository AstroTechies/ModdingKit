#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "DestructionDefinitionTable.generated.h"

class UDestructionBundleDefinition;
class APhysicalItem;
class UItemList;

UCLASS(Blueprintable, Blueprintable)
class UDestructionDefinitionTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<int32, UDestructionBundleDefinition *> Defaults;

    UPROPERTY(EditDefaultsOnly)
    TMap<TSubclassOf<APhysicalItem>, UDestructionBundleDefinition *> Overrides;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UItemList>> DebrisSpawningBlacklist;

    UDestructionDefinitionTable();
};
