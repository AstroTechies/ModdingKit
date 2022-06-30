#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EAstroMessageOfTheDayVersion.h"
#include "MessageOfTheDay.generated.h"

UCLASS(Blueprintable, BlueprintType)
class MESSAGEOFTHEDAY_API UMessageOfTheDay : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    EAstroMessageOfTheDayVersion Version;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText Title;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText LinkText;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString URL;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString BackgroundImageCDNKey;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FText> Messages;

    UMessageOfTheDay();
};
