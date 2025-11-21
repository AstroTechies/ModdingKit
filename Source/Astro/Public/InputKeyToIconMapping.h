#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputCoreTypes.h"
#include "InputKeyToIconMappingEntry.h"
#include "InputKeyToIconMapping.generated.h"

UCLASS(Blueprintable)
class UInputKeyToIconMapping : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingXbox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingPS4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingPS5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingKeyboardMouse;
    
    UInputKeyToIconMapping();

};

