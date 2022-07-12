#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ItemCatalogEntryDisplay.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UItemCatalogEntryDisplay : public UObject {
    GENERATED_BODY()
public:
    UItemCatalogEntryDisplay();
    UFUNCTION(BlueprintCallable)
    void K2_SetVisible(bool bIsVisible);
    
};

