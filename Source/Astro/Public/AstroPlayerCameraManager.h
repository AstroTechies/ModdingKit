#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PlayerCameraManager -FallbackName=PlayerCameraManager
#include "AstroPlayerCameraManager.generated.h"

class UCameraContext;

UCLASS(Blueprintable, NonTransient)
class AAstroPlayerCameraManager : public APlayerCameraManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCameraContext*> ContextStack;
    
public:
    AAstroPlayerCameraManager();
    UFUNCTION()
    void PopAllCameraContexts(UCameraContext* Context);
    
};

