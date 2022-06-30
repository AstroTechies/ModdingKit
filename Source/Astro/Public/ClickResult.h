#pragma once
#include "CoreMinimal.h"
#include "SlotClickResult.h"
#include "EClickBehavior.h"
#include "ClickResult.generated.h"

class UPrimitiveComponent;
class AActor;

USTRUCT(BlueprintType)
struct FClickResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSlotClickResult SlotResultPrimary;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FSlotClickResult SlotResultSecondary;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PrimaryComponent;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* PrimaryHoverComponent;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* TracedActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* PrimaryActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* SecondaryActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* TertiaryActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* PrimaryViewActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* SecondaryViewActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* TertiaryViewActor;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EClickBehavior PrimaryBehavior;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EClickBehavior SecondaryBehavior;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EClickBehavior TertiaryBehavior;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 PrimaryBehaviorMetadata;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bClickCaptured: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bSuppressQuickSelect: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bSlowVirtualCursorOnHover: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bSwapDisallowed: 1;
    
    ASTRO_API FClickResult();
};

