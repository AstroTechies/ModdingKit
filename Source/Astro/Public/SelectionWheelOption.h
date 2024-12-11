#pragma once
#include "CoreMinimal.h"
#include "EAstroSelectionWheelOptionGameMode.h"
#include "EAstroSelectionWheelOptionType.h"
#include "SelectionWheelOption.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FSelectionWheelOption {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObject> IconSoftPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroSelectionWheelOptionType OptionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OptionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroSelectionWheelOptionGameMode OptionGameMode;
    
    ASTRO_API FSelectionWheelOption();
};

