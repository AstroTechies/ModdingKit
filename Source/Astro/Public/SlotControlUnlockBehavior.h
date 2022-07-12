#pragma once
#include "CoreMinimal.h"
#include "UnlockBehavior.h"
#include "SlotReference.h"
#include "SlotControlUnlockBehavior.generated.h"

UCLASS(Blueprintable)
class ASTRO_API USlotControlUnlockBehavior : public UUnlockBehavior {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ControlledSlotRefs;
    
public:
    USlotControlUnlockBehavior();
};

