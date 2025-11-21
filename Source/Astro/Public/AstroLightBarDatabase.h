#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AstroLightBarData.h"
#include "EAstroLightBar.h"
#include "AstroLightBarDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroLightBarDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroLightBar, FAstroLightBarData> LightBarData;
    
    UAstroLightBarDatabase();

};

