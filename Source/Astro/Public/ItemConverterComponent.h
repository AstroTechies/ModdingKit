#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversion.h"
#include "AstroEntityComponent.h"
#include "SlotReference.h"
#include "PossibleItemConversion.h"
#include "AstroDatumRef.h"
#include "EItemConverterState.h"
#include "ItemConverterComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemConverterComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    TArray<FSlotReference> InputSlots;
    
    UPROPERTY(SaveGame)
    TArray<FSlotReference> OutputSlots;
    
    UPROPERTY()
    TArray<FPossibleItemConversion> PossibleConversions;
    
    UPROPERTY()
    TArray<FSlotReference> ExternalResourceSlots;
    
    UPROPERTY(SaveGame)
    TArray<FActiveItemConversion> ActiveItemConversions;
    
    UPROPERTY(SaveGame)
    TArray<FAstroDatumRef> VolatileItemEntityRefsToDetonate;
    
    UPROPERTY(SaveGame)
    bool bWantsToBeActive;
    
    UPROPERTY(SaveGame)
    EItemConverterState ConverterState;
    
    UPROPERTY(SaveGame)
    int32 ActiveConversionIDCounter;
    
    UPROPERTY(SaveGame)
    int32 SelectedOutputItemTypeIndex;
    
    ASTRO_API FItemConverterComponent();
};

