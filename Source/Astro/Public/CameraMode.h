#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CameraMode.generated.h"

class ACameraRigActor;

USTRUCT(BlueprintType)
struct FCameraMode {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FName Name;
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<ACameraRigActor> CameraRigClass;
    
    UPROPERTY()
    ACameraRigActor* CameraRig;
    
    ASTRO_API FCameraMode();
};

