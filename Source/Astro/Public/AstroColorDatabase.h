#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroColor.h"
#include "UObject/NoExportTypes.h"
#include "AstroColorDatabase.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstroColorDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<EAstroColor, FLinearColor> ColorDatabase;

    UAstroColorDatabase();
};
