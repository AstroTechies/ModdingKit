#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "StoreMenuCameraContext.generated.h"

class APlayController;

UCLASS(Blueprintable)
class UStoreMenuCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayController* Controller;
    
    UStoreMenuCameraContext();

};

