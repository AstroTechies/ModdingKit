#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "AstroDiscreteInputDefinition.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "AstroDiscreteInputDefinitionDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroDiscreteInputDefinitionDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroDiscreteInputOptionPlayerFacing, FAstroDiscreteInputDefinition> DiscreteInputDefinitions;
    
    UAstroDiscreteInputDefinitionDatabase();
};

