#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "AstroPlayerCameraManager.generated.h"

class UCameraContext;

UCLASS(Blueprintable, NonTransient)
class AAstroPlayerCameraManager : public APlayerCameraManager {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCameraContext*> ContextStack;
    
public:
    AAstroPlayerCameraManager(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void PopAllCameraContexts(UCameraContext* Context);
    
};

