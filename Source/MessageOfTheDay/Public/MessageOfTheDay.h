#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "EAstroMessageOfTheDayVersion.h"
#include "MessageOfTheDay.generated.h"

UCLASS(BlueprintType)
class MESSAGEOFTHEDAY_API UMessageOfTheDay : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadOnly)
    EAstroMessageOfTheDayVersion Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText Title;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FText LinkText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString URL;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString BackgroundImageCDNKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FText> Messages;
    
    UMessageOfTheDay();
};

