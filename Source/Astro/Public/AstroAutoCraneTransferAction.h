#pragma once
#include "CoreMinimal.h"
#include "AstroPlayMontageAction.h"
#include "SlotReference.h"
#include "AstroAutoCraneTransferAction.generated.h"

class UAnimationAsset;

UCLASS(Blueprintable)
class ASTRO_API UAstroAutoCraneTransferAction : public UAstroPlayMontageAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ItemSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference TransferSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* EndingAnimation;
    
public:
    UAstroAutoCraneTransferAction();
};

