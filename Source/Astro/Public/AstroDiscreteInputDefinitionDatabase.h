#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroDiscreteInputOptionPlayerFacing.h"
#include "AstroDiscreteInputDefinition.h"
#include "AstroDiscreteInputDefinitionDatabase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstroDiscreteInputDefinitionDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<EAstroDiscreteInputOptionPlayerFacing, FAstroDiscreteInputDefinition> DiscreteInputDefinitions;

    UAstroDiscreteInputDefinitionDatabase();
};
