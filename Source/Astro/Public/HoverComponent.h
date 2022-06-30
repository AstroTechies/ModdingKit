#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "HoverComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UHoverComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float SpinSpeed;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector RotateAxis;

    UHoverComponent();
};
