#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "SnailBehaviorData.h"
#include "ESnailBehaviorTriggerType.h"
#include "SnailBehaviorTable.generated.h"

UCLASS(Blueprintable)
class USnailBehaviorTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESnailBehaviorTriggerType, FSnailBehaviorData> DefaultBehaviorMap;
    
    USnailBehaviorTable();
};

