#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentContainer.h"
#include "AstroDatumRef.h"
#include "ItemConverterComponent.h"
#include "ItemConverterComponentContainer.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UItemConverterComponentContainer : public UAstroEntityComponentContainer
{
    GENERATED_BODY()
public:
    UItemConverterComponentContainer();
    UFUNCTION(BlueprintPure)
    static FItemConverterComponent GetItemConverterComponent(FAstroDatumRef ItemConverterComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FItemConverterComponent FindItemConverterComponent(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
