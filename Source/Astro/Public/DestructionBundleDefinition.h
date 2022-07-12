#pragma once
#include "CoreMinimal.h"
#include "DebrisItem.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "DestructionBundleDefinition.generated.h"

UCLASS(Blueprintable)
class UDestructionBundleDefinition : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDebrisItem> DebrisItems;
    
    UDestructionBundleDefinition();
};

