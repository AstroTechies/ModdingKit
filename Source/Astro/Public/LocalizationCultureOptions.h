#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LocalizationCultureOptions.generated.h"

UCLASS(Blueprintable)
class ULocalizationCultureOptions : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> DisplayLanguageToCultureMapping;
    
    ULocalizationCultureOptions();

};

