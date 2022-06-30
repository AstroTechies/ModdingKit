#pragma once
#include "CoreMinimal.h"
#include "AstroPlayMontageAction.h"
#include "SlotReference.h"
#include "AstroAutoCraneTransferAction.generated.h"

class UAnimationAsset;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroAutoCraneTransferAction : public UAstroPlayMontageAction
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY()
    FSlotReference ItemSlot;

    UPROPERTY()
    FSlotReference TransferSlot;

    UPROPERTY()
    UAnimationAsset *EndingAnimation;

public:
    UAstroAutoCraneTransferAction();
};
