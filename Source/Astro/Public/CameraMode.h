#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CameraMode.generated.h"

class ACameraRigActor;

USTRUCT(BlueprintType)
struct FCameraMode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACameraRigActor> CameraRigClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ACameraRigActor* CameraRig;
    
    ASTRO_API FCameraMode();
};

