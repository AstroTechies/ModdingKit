#pragma once
#include "CoreMinimal.h"
#include "SlotReference.generated.h"

class USlotsComponent;

USTRUCT(BlueprintType)
struct FSlotReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    USlotsComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName SlotName;

	friend uint32 GetTypeHash(const FSlotReference& Other) {
		return 0;
	}
    
    ASTRO_API FSlotReference();
};

