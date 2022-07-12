#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "GameMenuPopoutCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable)
class UGameMenuPopoutCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayController* Controller;
    
    UGameMenuPopoutCameraContext();
};

