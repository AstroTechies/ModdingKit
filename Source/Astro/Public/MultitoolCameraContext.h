#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "MultitoolCameraContext.generated.h"

class UMultiTool;

UCLASS(Blueprintable)
class UMultitoolCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultiTool* MultiTool;
    
    UMultitoolCameraContext();
};

