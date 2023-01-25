#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "PackageActor.generated.h"

class UAstroActionComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API APackageActor : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    APackageActor();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void Authority_Unpack();
    
};

