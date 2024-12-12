#pragma once
#include "CoreMinimal.h"
#include "TetherAttachComponent.h"
#include "VehicleTetherAttachComponent.generated.h"

class UTetherNetwork;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UVehicleTetherAttachComponent : public UTetherAttachComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* PreviousClosestTetherPost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTetherNetwork* PreviousTetherNetwork;
    
public:
    UVehicleTetherAttachComponent(const FObjectInitializer& ObjectInitializer);

};

