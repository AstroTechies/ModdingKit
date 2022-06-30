#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LocalizationCultureOptions.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ULocalizationCultureOptions : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TMap<FString, FString> DisplayLanguageToCultureMapping;

    ULocalizationCultureOptions();
};
