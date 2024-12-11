#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DebrisItem.h"
#include "DestructionBundleDefinition.generated.h"

UCLASS(Blueprintable)
class UDestructionBundleDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebrisItem> DebrisItems;
    
    UDestructionBundleDefinition();

};

