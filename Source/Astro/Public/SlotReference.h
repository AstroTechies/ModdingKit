#pragma once
#include "CoreMinimal.h"
#include "SlotReference.generated.h"

class USlotsComponent;

USTRUCT(BlueprintType)
struct FSlotReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta=(AllowPrivateAccess=true))
    USlotsComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    ASTRO_API FSlotReference();
};

FORCEINLINE uint32 GetTypeHash(const FSlotReference& SlotReference) {
    return 0;
}