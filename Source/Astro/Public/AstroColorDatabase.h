#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "EAstroColor.h"
#include "AstroColorDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroColorDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroColor, FLinearColor> ColorDatabase;
    
    UAstroColorDatabase();

};

