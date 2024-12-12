#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
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

