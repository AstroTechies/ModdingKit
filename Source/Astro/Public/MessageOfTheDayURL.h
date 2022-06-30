#pragma once
#include "CoreMinimal.h"
#include "MessageOfTheDayURL.generated.h"

USTRUCT()
struct FMessageOfTheDayURL {
    GENERATED_BODY()
public:
    UPROPERTY()
    FString CultureCode;
    
    UPROPERTY(EditAnywhere)
    FString FriendlyName;
    
    UPROPERTY(EditAnywhere)
    FString URL;
    
    ASTRO_API FMessageOfTheDayURL();
};

