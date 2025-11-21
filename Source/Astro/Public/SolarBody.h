#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "VoxelMaterial.h"
#include "EGravityType.h"
#include "SolarBody.generated.h"

class ASolarBody;
class UAstroSaveCustomArchiveProxy;
class UObject;
class USceneComponent;
class UStaticMesh;
class UTexture2D;
class UVoxelVolumeComponent;

UCLASS(Blueprintable)
class ASTRO_API ASolarBody : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrbitAxisUpdated, FVector, NewOrbitAxis);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OrbitingBodyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* IconMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* WidgetIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PlanetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    UObject* TooltipResourceObjectBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    FVector2D TooltipScreenOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta=(AllowPrivateAccess=true))
    FVector2D CustomBadgeSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WorldSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGravityType GravityType;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GravityVector;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityCylinderHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float Gravity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitalMass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    float DayLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondsPerSkyboxRevolution;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool FreezeOrbit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Stationary;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 IsFakeTerrainObject: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ShuttleOrbitAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SolarVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASolarBody* OrbitingBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OrbitAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SunExposureModifier;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnOrbitAxisUpdated OnOrbitAxisUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_OrbitAxis, meta=(AllowPrivateAccess=true))
    FVector ActiveOrbitAxis;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FVector OrbitAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FVector OrbitAxisCreative;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAllowsCreativeFlight: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomizeSeedForBuild;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomizeSeedForPIE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ExplicitSeeds;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FVector InitialOrbitOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FVector InitialOrbitAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FTransform InitialTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    float LastCalculatedNormalizedDayTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    float DayTimeBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    float LastSetOrbitAxisRotation;
    
public:
    ASolarBody(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetOrbitAxisRotation(float rads);
    
    UFUNCTION(BlueprintCallable)
    void SetNormalizedDayTime(float dayTime);
    
    UFUNCTION(BlueprintCallable)
    void SetDayLength(float newDayLength);
    
    UFUNCTION(BlueprintCallable)
    void SetBodyTransform(const FTransform& Transform);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnRep_OrbitAxis();
    
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerPlanetSelectionEnd(ASolarBody* newSolarBody);
    
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerPlanetSelectionBegin(ASolarBody* homeSolarBody);
    
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerLocalSolarBodyChanged(ASolarBody* newLocalSolarBody);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCreativeModeEnabledChanged(bool CreativeModeEnabled);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVoxelVolumeComponent* GetVoxelVolumeComponent(const FVector& InLocation) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVoxelMaterial GetTerrainMaterial(const FVector& Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTerrainDensity(const FVector& Location) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetProxyComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetProxyCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetOrbitAxis();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetNormalizedDayTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLastOrbitAxisRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetDayRotationOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetCenterComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCenter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetBodyTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanBeVisitedByPlayer() const;
    
};

