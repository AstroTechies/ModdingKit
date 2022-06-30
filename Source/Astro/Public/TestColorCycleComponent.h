#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "TestColorCycleComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UTestColorCycleComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FLinearColor ColorChangePerSecond;

    UPROPERTY(EditAnywhere)
    FLinearColor MinColor;

    UPROPERTY(EditAnywhere)
    FLinearColor MaxColor;

    UTestColorCycleComponent();
};
