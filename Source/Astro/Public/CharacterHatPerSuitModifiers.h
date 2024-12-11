#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterHatPerSuitModifiers.generated.h"

class UMaterialInstanceConstant;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FCharacterHatPerSuitModifiers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UMaterialInstanceConstant> MaterialOverride;
    
    ASTRO_API FCharacterHatPerSuitModifiers();
};

