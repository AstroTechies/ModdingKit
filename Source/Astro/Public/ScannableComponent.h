#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ScannableStatus.h"
#include "EScannableType.h"
#include "Engine/EngineTypes.h"
#include "ScannableComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UScannableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FScannableStatus Status;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FName ScannableName;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EScannableType ScannableType;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference LocationComponentRef;

    UPROPERTY(EditDefaultsOnly)
    float RecalculateSolarBodyDistanceSquared;

public:
    UScannableComponent();
};
