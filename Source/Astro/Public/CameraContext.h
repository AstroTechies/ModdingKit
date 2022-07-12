#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "CameraContextSignalDelegate.h"
#include "CameraContext.generated.h"

class UCustomCameraRigComponent;

UCLASS(Blueprintable, DefaultToInstanced)
class UCameraContext : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraContextSignal OnOwningRigDestroyed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UCustomCameraRigComponent* OwningComponent;
    
    UPROPERTY(EditAnywhere)
    uint8 Priority;
    
    UCameraContext();
};

