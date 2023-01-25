#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentContainer.h"
#include "ItemConverterComponent.h"
#include "ItemConverterComponentContainer.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UItemConverterComponentContainer : public UAstroEntityComponentContainer {
    GENERATED_BODY()
public:
    UItemConverterComponentContainer();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FItemConverterComponent GetItemConverterComponent(FAstroDatumRef ItemConverterComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FItemConverterComponent FindItemConverterComponent(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

