#pragma once
#include "CoreMinimal.h"
#include "ItemTypeReference.generated.h"

USTRUCT(BlueprintType)
struct FItemTypeReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* ItemType;
    
    TERRAIN2_API FItemTypeReference();
};

