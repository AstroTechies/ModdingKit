#pragma once
#include "CoreMinimal.h"
#include "VirusProtectionKitDetailsConfigData.generated.h"

USTRUCT(BlueprintType)
struct FVirusProtectionKitDetailsConfigData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StormDataAccumulationThreshhold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FText> EffectsBullets;
    
    ASTRO_API FVirusProtectionKitDetailsConfigData();
};

