#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroSaveAsset.generated.h"

class UWorld;

UCLASS(Blueprintable)
class ASTRO_API UAstroSaveAsset : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> SaveLevel;
    
    UPROPERTY(EditAnywhere)
    TArray<uint8> SaveData;
    
    UAstroSaveAsset();
};

