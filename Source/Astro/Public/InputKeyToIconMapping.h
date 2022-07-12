#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "InputKeyToIconMappingEntry.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
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
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingSwitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FKey, FInputKeyToIconMappingEntry> KeyToIconMappingKeyboardMouse;
    
    UInputKeyToIconMapping();
};

