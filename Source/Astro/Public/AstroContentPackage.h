#pragma once
#include "CoreMinimal.h"
#include "Engine/PrimaryAssetLabel.h"
#include "AstroEncryptionOptions.h"
#include "AstroContentPackage.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UAstroContentPackage : public UPrimaryAssetLabel {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroEncryptionOptions EncryptionOptions;
    
    UAstroContentPackage();
};

