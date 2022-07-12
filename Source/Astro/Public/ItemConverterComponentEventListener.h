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
    UFUNCTION()
    void OnItemStateChangedInExternalResourceSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemSetInInputSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemReleasedFromOutputSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemReleasedFromInputSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemDestroyedInInputSlot(APhysicalItem* Item);
    
};

