#pragma once
#include "CoreMinimal.h"
#include "AstroEntityComponentSubobject.h"
#include "ItemConverterComponentEventListener.generated.h"

class APhysicalItem;

UCLASS(Blueprintable)
class UItemConverterComponentEventListener : public UAstroEntityComponentSubobject {
    GENERATED_BODY()
public:
    UItemConverterComponentEventListener();
    UFUNCTION(BlueprintCallable)
    void OnItemStateChangedInExternalResourceSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemSetInInputSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemReleasedFromOutputSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemReleasedFromInputSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemDestroyedInInputSlot(APhysicalItem* Item);
    
};

