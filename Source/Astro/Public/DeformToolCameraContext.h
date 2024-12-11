#pragma once
#include "CoreMinimal.h"
#include "CameraContext.h"
#include "DeformToolCameraContext.generated.h"

class ADeformTool;

UCLASS(Blueprintable)
class UDeformToolCameraContext : public UCameraContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ADeformTool* DeformTool;
    
    UDeformToolCameraContext();

};

