#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "CustomGameModifierData.h"
#include "AstroCGMModifierCategoryDefaultValuesDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroCGMModifierCategoryDefaultValuesDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, FCustomGameModifierData> ModifierTagToModifierDefaultData;
    
    UAstroCGMModifierCategoryDefaultValuesDatabase();

};

