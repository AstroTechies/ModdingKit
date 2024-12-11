#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "AstroCGMDisableItemLocDatabase.generated.h"

class UItemType;

UCLASS(Blueprintable)
class UAstroCGMDisableItemLocDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UItemType>, FText> ItemTypeToLocTextMap;
    
    UAstroCGMDisableItemLocDatabase();

};

