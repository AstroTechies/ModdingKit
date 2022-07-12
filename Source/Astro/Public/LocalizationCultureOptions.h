#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "LocalizationCultureOptions.generated.h"

UCLASS(Blueprintable)
class ULocalizationCultureOptions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> DisplayLanguageToCultureMapping;
    
    ULocalizationCultureOptions();
};

