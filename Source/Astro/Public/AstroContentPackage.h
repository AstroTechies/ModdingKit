#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryAssetLabel -FallbackName=PrimaryAssetLabel
#include "Engine/PrimaryAssetLabel.h"
#include "AstroEncryptionOptions.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimaryAssetLabel -FallbackName=PrimaryAssetLabel
#include "AstroContentPackage.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroContentPackage : public UPrimaryAssetLabel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroEncryptionOptions EncryptionOptions;
    
    UAstroContentPackage();
};

