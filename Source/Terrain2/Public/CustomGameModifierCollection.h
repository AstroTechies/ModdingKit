#pragma once
#include "CoreMinimal.h"
#include "CustomGameModifierData.h"
#include "CustomGameModifierCollection.generated.h"

USTRUCT(BlueprintType)
struct FCustomGameModifierCollection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NotReplicated, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<FString, int32> ModifierIndexes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FCustomGameModifierData> Modifiers;
    
    TERRAIN2_API FCustomGameModifierCollection();
};

