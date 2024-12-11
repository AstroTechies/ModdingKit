#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TetherDecoration.h"
#include "TetherDecorationConfig.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UTetherDecorationConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTetherDecoration> DecorationOptions;
    
    UTetherDecorationConfig();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetNextTetherDecorationIndex();
    
};

