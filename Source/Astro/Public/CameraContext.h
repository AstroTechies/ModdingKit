#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraContextSignalDelegate.h"
#include "CameraContext.generated.h"

class UCustomCameraRigComponent;

UCLASS(Blueprintable, DefaultToInstanced)
class UCameraContext : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraContextSignal OnOwningRigDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCustomCameraRigComponent* OwningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Priority;
    
    UCameraContext();

};

