#pragma once
#include "CoreMinimal.h"
#include "TetherDecoration.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "TetherDecorationConfig.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UTetherDecorationConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTetherDecoration> DecorationOptions;
    
    UTetherDecorationConfig();
    UFUNCTION(BlueprintPure)
    static int32 GetNextTetherDecorationIndex();
    
};

