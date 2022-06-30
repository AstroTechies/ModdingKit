#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "DeformableInterfaceT2.h"
#include "DeformSafeZoneComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class UDeformSafeZoneComponent : public UActorComponent, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float Radius;

    UPROPERTY(EditAnywhere)
    FVector Location;

    UDeformSafeZoneComponent();

    // Fix for true pure virtual functions not being implemented
};
