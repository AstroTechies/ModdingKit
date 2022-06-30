#pragma once
#include "CoreMinimal.h"
#include "AstroPackagingAction.h"
#include "AstroUnpackAction.generated.h"

class UDeployableItemPackageComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroUnpackAction : public UAstroPackagingAction
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export)
    UDeployableItemPackageComponent *DeployableItemComponent;

public:
    UAstroUnpackAction();
    UFUNCTION(BlueprintCallable)
    void SetDeployableItem(UDeployableItemPackageComponent *DeployableItemPackageComponent);
};
