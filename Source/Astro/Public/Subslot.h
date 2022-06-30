#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subslot.generated.h"

class USubslot;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API USubslot : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<USceneComponent *> Slots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<USubslot *> SubSlots;

    USubslot();
    UFUNCTION(BlueprintPure)
    static USubslot *MakeSubslot(UObject *WorldContextObject, const TArray<USceneComponent *> SlotComponents, const TArray<USubslot *> &SubSubSlots);
};
