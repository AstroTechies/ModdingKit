#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HazardTargetingData.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType)
class UHazardTargetingData : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<AActor *> Targets;

    UHazardTargetingData();
};
