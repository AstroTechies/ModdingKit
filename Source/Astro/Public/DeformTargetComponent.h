#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "DeformTargetSignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "DeformTargetComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDeformTargetComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> TargetSlots;

    UPROPERTY(BlueprintAssignable)
    FDeformTargetSignal OnDeform;

    UDeformTargetComponent();
    UFUNCTION(BlueprintCallable)
    FTransform GetDeformTarget(const FVector &sourceLocation);
};
