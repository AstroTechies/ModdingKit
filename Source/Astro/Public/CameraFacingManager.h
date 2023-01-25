#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "CameraFacingManager.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class UCameraFacingManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> SceneComponents;
    
public:
    UCameraFacingManager();
};

