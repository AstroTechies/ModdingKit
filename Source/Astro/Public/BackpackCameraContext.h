#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "BackpackCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable)
class UBackpackCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayController* Controller;
    
    UBackpackCameraContext();
};

