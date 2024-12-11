#pragma once
#include "CoreMinimal.h"
#include "ActiveItemConversion.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponent.h"
#include "EItemConverterState.h"
#include "PossibleItemConversion.h"
#include "SlotReference.h"
#include "ItemConverterComponent.generated.h"

USTRUCT(BlueprintType)
struct FItemConverterComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPossibleItemConversion> PossibleConversions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ExternalResourceSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FActiveItemConversion> ActiveItemConversions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroDatumRef> VolatileItemEntityRefsToDetonate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bWantsToBeActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EItemConverterState ConverterState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ActiveConversionIDCounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SelectedOutputItemTypeIndex;
    
    ASTRO_API FItemConverterComponent();
};

