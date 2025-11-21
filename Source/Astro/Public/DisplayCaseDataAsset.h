#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CollectionData.h"
#include "DisplayCaseDataAsset.generated.h"

UCLASS(Blueprintable)
class UDisplayCaseDataAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCollectionData> Collections;
    
    UDisplayCaseDataAsset();

};

