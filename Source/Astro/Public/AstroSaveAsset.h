#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroSaveAsset.generated.h"

class UWorld;

UCLASS(Blueprintable)
class ASTRO_API UAstroSaveAsset : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> SaveLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<uint8> SaveData;
    
    UAstroSaveAsset();

};

