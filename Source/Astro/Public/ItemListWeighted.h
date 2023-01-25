#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ItemSpecifier.h"
#include "Templates/SubclassOf.h"
#include "ItemListWeighted.generated.h"

class UItemListWeighted;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API UItemListWeighted : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FItemSpecifier> ItemTypes;
    
    UItemListWeighted();
    UFUNCTION(BlueprintCallable)
    TSubclassOf<UItemType> PickItem();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemListWeighted* ItemSpawnListDefault(TSubclassOf<UItemListWeighted> Type);
    
};

