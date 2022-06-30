#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "ItemSpecifier.h"
#include "ItemListWeighted.generated.h"

class UItemListWeighted;
class UItemType;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UItemListWeighted : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FItemSpecifier> ItemTypes;

    UItemListWeighted();
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UItemType> PickItem();

    UFUNCTION(BlueprintPure)
    static UItemListWeighted *ItemSpawnListDefault(TSubclassOf<UItemListWeighted> Type);
};
