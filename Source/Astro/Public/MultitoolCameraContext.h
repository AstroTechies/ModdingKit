#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "MultitoolCameraContext.generated.h"

class UMultiTool;

UCLASS(Blueprintable)
class UMultitoolCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UMultiTool* MultiTool;
    
    UMultitoolCameraContext();
};

