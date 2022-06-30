#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "PackageActor.generated.h"

class UAstroActionComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API APackageActor : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UAstroActionComponent *ActionComponent;

    APackageActor();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void Authority_Unpack();
};
