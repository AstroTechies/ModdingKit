#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayGlobals.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UGameplayGlobals : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float MaxSlotAutoselectRange;

    UGameplayGlobals();
};
