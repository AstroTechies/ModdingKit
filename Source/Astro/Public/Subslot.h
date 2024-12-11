#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Subslot.generated.h"

class USceneComponent;
class USubslot;

UCLASS(Blueprintable)
class ASTRO_API USubslot : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USubslot*> SubSlots;
    
    USubslot();

    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static USubslot* MakeSubslot(UObject* WorldContextObject, const TArray<USceneComponent*> SlotComponents, const TArray<USubslot*>& SubSubSlots);
    
};

