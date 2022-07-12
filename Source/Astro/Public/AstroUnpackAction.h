#pragma once
#include "CoreMinimal.h"
#include "AstroPackagingAction.h"
#include "AstroUnpackAction.generated.h"

class UDeployableItemPackageComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroUnpackAction : public UAstroPackagingAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDeployableItemPackageComponent* DeployableItemComponent;
    
public:
    UAstroUnpackAction();
    UFUNCTION(BlueprintCallable)
    void SetDeployableItem(UDeployableItemPackageComponent* DeployableItemPackageComponent);
    
};

