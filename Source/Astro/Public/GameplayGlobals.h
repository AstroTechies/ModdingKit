#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayGlobals.generated.h"

UCLASS(Blueprintable)
class UGameplayGlobals : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSlotAutoselectRange;
    
    UGameplayGlobals();

};

