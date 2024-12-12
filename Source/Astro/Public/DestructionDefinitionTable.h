#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "DestructionDefinitionTable.generated.h"

class APhysicalItem;
class UDestructionBundleDefinition;
class UItemList;

UCLASS(Blueprintable)
class UDestructionDefinitionTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, UDestructionBundleDefinition*> Defaults;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<APhysicalItem>, UDestructionBundleDefinition*> Overrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemList>> DebrisSpawningBlacklist;
    
    UDestructionDefinitionTable();

};

