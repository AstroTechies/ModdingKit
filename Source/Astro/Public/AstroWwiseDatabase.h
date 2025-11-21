#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroWwiseDevice.h"
#include "AstroWwiseDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroWwiseDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroWwiseDevice, FString> WwiseData;
    
    UAstroWwiseDatabase();

};

