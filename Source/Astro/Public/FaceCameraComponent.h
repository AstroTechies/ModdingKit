#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FaceCameraComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UFaceCameraComponent : public USceneComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool MaintainUp;

    UFaceCameraComponent();
};
