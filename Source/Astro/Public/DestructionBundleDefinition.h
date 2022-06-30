#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DebrisItem.h"
#include "DestructionBundleDefinition.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UDestructionBundleDefinition : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TArray<FDebrisItem> DebrisItems;

    UDestructionBundleDefinition();
};
