#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ItemCatalogEntryDisplay.generated.h"

UCLASS(Blueprintable, Abstract, BlueprintType)
class ASTRO_API UItemCatalogEntryDisplay : public UObject
{
    GENERATED_BODY()
public:
    UItemCatalogEntryDisplay();
    UFUNCTION(BlueprintCallable)
    void K2_SetVisible(bool bIsVisible);
};
