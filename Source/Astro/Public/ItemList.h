#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "ItemList.generated.h"

class UItemType;

UCLASS(Blueprintable, Blueprintable, BlueprintType)
class ASTRO_API UItemList : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> ItemTypes;

    UItemList();
};
