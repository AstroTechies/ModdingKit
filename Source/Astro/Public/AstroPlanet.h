#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AtmosphericResource.h"
#include "SolarBody.h"
#include "GatewayObjectPlacementProperties.h"
#include "EPlanetIdentifier.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DeformationParamsT2.h"
#include "UObject/NoExportTypes.h"
#include "VoxelMaterial.h"
#include "AstroPlanet.generated.h"

class UObject;
class UVoxelVolumeComponent;
class UItemType;
class UMaterial;
class UMaterialInstanceDynamic;
class UMaterialParameterCollection;
class UStaticMeshComponent;
class ADayNight;
class UChildActorComponent;
class USceneComponent;
class UBoundedVoxelVolumeModifier;
class AActor;
class ANavpointManagerActor;
class APlanetProxyActor;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AAstroPlanet : public ASolarBody
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    EPlanetIdentifier PlanetIdentifier;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> PlanetItemType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UVoxelVolumeComponent *PlanetaryVoxelVolume;

    UPROPERTY(Export)
    UVoxelVolumeComponent *DefaultVoxelVolume;

    UPROPERTY(Transient)
    TArray<UObject *> CachedT2Deformables;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    int32 Seed;

    UPROPERTY(EditAnywhere)
    TArray<int32> ExplicitSeeds;

    UPROPERTY(EditAnywhere)
    bool VerticalZLandingZone;

    UPROPERTY(EditAnywhere)
    TArray<FText> SwapStartPlanets;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool Enable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 Difficulty;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FAtmosphericResource> AtmosphericResources;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool Cutaway;

    UPROPERTY(EditAnywhere, SaveGame)
    bool CenterOrigin;

    UPROPERTY(EditAnywhere)
    bool RandomizeSeedForBuild;

    UPROPERTY(EditAnywhere)
    bool RandomizeSeedForPIE;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LodMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float VoxelSize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SunExposureModifier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WindIntensityModifier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor AmbientColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float AmbientIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DaytimeSkyColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DaytimeSkyIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor NightSkyColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float NightSkyIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FogFalloff;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FogPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FogAtmosphereHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FogAtmosphereThickness;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor FogColorCeiling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor FogColorFloor;

    UPROPERTY(EditAnywhere)
    float DaytimeEnvironmentFogContribution;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor FogColorNightCeiling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor FogColorNightFloor;

    UPROPERTY(EditAnywhere)
    float NighttimeEnvironmentFogContribution;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor FogColorUnderground;

    UPROPERTY(EditAnywhere)
    float FogUndergroundThickness;

    UPROPERTY(EditAnywhere)
    float FogMaxOpacity;

    UPROPERTY(EditAnywhere)
    FLinearColor FogSunHaloColor;

    UPROPERTY(EditAnywhere)
    float FogSunHaloIntensity;

    UPROPERTY(EditAnywhere)
    float FogSunHaloPower;

    UPROPERTY(EditAnywhere)
    float WindScale;

    UPROPERTY(EditAnywhere)
    float WindNoiseMovement;

    UPROPERTY(EditAnywhere)
    float WindDirectionChangeRate;

    UPROPERTY(EditAnywhere)
    float WindIntensityChangeRate;

    UPROPERTY(EditAnywhere)
    float AmbientWind;

    UPROPERTY(EditDefaultsOnly)
    float MaxFlightHeightAdjustment;

    UPROPERTY(EditAnywhere)
    FGatewayObjectPlacementProperties GatewayObjectPlacementProperties;

    UPROPERTY(EditAnywhere)
    UMaterial *FogMaterial;

    UPROPERTY()
    UMaterialInstanceDynamic *FogMaterialDynamic;

    UPROPERTY()
    UMaterialParameterCollection *FogMaterialParameterCollection;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IsLocallyVisible;

protected:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *FogMesh;

    UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Export, meta = (AllowPrivateAccess = true))
    UChildActorComponent *ProxyComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *ProxyMeshComponent;

    UPROPERTY(Export, Transient)
    TArray<UBoundedVoxelVolumeModifier *> GatewayObjectPlacementVoxelVolumeModifiers;

    UPROPERTY(EditAnywhere)
    AActor *LowRezClouds;

    UPROPERTY(EditAnywhere)
    AActor *LowRezProxyClouds;

    UPROPERTY(EditAnywhere)
    AActor *AtmostphericFeatures;

private:
    UPROPERTY(Transient)
    AActor *SunActor;

    UPROPERTY(Transient)
    ADayNight *DayNightActor;

    UPROPERTY(Replicated, Transient)
    ANavpointManagerActor *NavpointManagerOwner;

public:
    AAstroPlanet();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void UpdateHasPlayersOnPlanet(ASolarBody *SolarBody);

public:
    UFUNCTION(BlueprintPure)
    FLinearColor SampleFog(const FVector &Origin, const FVector &Ray);

private:
    UFUNCTION()
    void OnDeformationComplete(const FDeformationParamsT2 &params);

public:
    UFUNCTION(BlueprintPure)
    bool LocationInAtmosphere(const FVector &Location);

    UFUNCTION(BlueprintPure)
    FVector GetWindDirectionAt(const FVector &Location, float &Intensity);

    UFUNCTION(BlueprintPure)
    FVector GetTerrainNormal(const FVector &Location);

    UFUNCTION(BlueprintPure)
    FVoxelMaterial GetTerrainMaterial(const FVector &Location);

    UFUNCTION(BlueprintPure)
    float GetTerrainDensity(const FVector &Location);

    UFUNCTION(BlueprintPure)
    float GetRadius() const;

    UFUNCTION(BlueprintPure)
    APlanetProxyActor *GetProxy();

    UFUNCTION(BlueprintPure)
    FTransform GetPlanetTransform();

    UFUNCTION(BlueprintPure)
    FTransform GetPlanetToProxyTransform();

    UFUNCTION(BlueprintCallable)
    FVector GetNorthVector();

    UFUNCTION(BlueprintPure)
    ADayNight *GetDayNightActor() const;
};
