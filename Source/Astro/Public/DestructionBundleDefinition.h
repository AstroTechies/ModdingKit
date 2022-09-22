#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
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

