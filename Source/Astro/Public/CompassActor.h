#pragma once
#include "CoreMinimal.h"
#include "NavpointVisualData.h"
#include "NavpointTypeConfig.h"
#include "GameFramework/Actor.h"
#include "ENavpointType.h"
#include "UObject/NoExportTypes.h"
#include "CompassActor.generated.h"

class UStaticMesh;
class UMaterialInstanceDynamic;
class UMaterial;
class UStaticMeshComponent;
class UCurveFloat;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ACompassActor : public AActor
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *RingsMeshAsset;

    UPROPERTY(EditDefaultsOnly)
    UMaterial *RingsMaterialAsset;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *ElevationLineMesh;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *DistanceCurve;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *NavpointScaleCurve;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *NavpointOpacityCurve;

    UPROPERTY(EditDefaultsOnly)
    float MaxNavpointDistanceWithinCompassInterior;

    UPROPERTY(EditDefaultsOnly)
    float MaxNavpointDistanceOnCompassPerimeter;

    UPROPERTY(EditDefaultsOnly)
    float MaxNavpointElevationChange;

    UPROPERTY(EditDefaultsOnly)
    float MaxNavpointIconDistance;

    UPROPERTY(EditDefaultsOnly)
    float MaxNavpointIconHeight;

    UPROPERTY(EditDefaultsOnly)
    float CompassRingsScale;

    UPROPERTY(EditDefaultsOnly)
    float NavpointScale;

    UPROPERTY(EditDefaultsOnly)
    float NavpointIconMeshRadius;

    UPROPERTY(EditDefaultsOnly)
    float NavpointIconMeshHalfHeight;

    UPROPERTY(EditDefaultsOnly)
    float NavpointMinScaleOnPerimeter;

    UPROPERTY(EditDefaultsOnly)
    float NavpointMaxScaleOnPerimeter;

    UPROPERTY(EditDefaultsOnly)
    float NavpointFadeTime;

    UPROPERTY(EditDefaultsOnly)
    float MinOpacityCutoutThreshold;

    UPROPERTY(EditDefaultsOnly)
    uint8 NavpointCap;

    UPROPERTY(EditDefaultsOnly)
    FNavpointTypeConfig DefaultNavpointConfig;

    UPROPERTY(EditDefaultsOnly)
    TMap<ENavpointType, FNavpointTypeConfig> NavpointTypeConfig;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *RingsMaterial;

    UPROPERTY(Export, Transient)
    UStaticMeshComponent *Rings;

    UPROPERTY()
    TMap<FGuid, FNavpointVisualData> Navpoints;

    UPROPERTY()
    TArray<FNavpointVisualData> UnusedNavpointVisuals;

public:
    ACompassActor();

protected:
    UFUNCTION()
    void HandleUserSettingsChanged();

    UFUNCTION()
    void HandleOrbitalNavLaunch();

    UFUNCTION()
    void HandleNavpointRemoved(const FGuid &NavpointID);

    UFUNCTION()
    void HandleNavpointAdded(const FGuid &NavpointID);

    UFUNCTION()
    void HandleDrivingStatusChanged();
};
