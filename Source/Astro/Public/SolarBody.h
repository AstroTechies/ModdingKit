#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EGravityType.h"
#include "UObject/NoExportTypes.h"
#include "SolarBody.generated.h"

class UStaticMesh;
class ASolarBody;
class UObject;
class UTexture2D;
class UAstroSaveCustomArchiveProxy;
class USceneComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ASolarBody : public AActor
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOrbitAxisUpdated, FVector, NewOrbitAxis);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString OrbitingBodyName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText Name;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *IconMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *WidgetIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName PlanetType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText TooltipSubtitle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText TooltipDescription;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta = (AllowPrivateAccess = true))
    UObject *TooltipResourceObjectBadge;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta = (AllowPrivateAccess = true))
    FVector2D TooltipScreenOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SimpleDisplay, meta = (AllowPrivateAccess = true))
    FVector2D CustomBadgeSize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WorldSize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EGravityType GravityType;

    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector GravityVector;

    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float GravityCylinderHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta = (AllowPrivateAccess = true))
    float Gravity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float GravityRadius;

    UPROPERTY(EditAnywhere)
    float OrbitalMass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta = (AllowPrivateAccess = true))
    float DayLength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SecondsPerSkyboxRevolution;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool FreezeOrbit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool Stationary;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FVector SolarVelocity;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ASolarBody *OrbitingBody;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float OrbitDistance;

    UPROPERTY(BlueprintAssignable)
    FOnOrbitAxisUpdated OnOrbitAxisUpdated;

    UPROPERTY(BlueprintReadWrite, Transient, ReplicatedUsing = OnRep_OrbitAxis, meta = (AllowPrivateAccess = true))
    FVector ActiveOrbitAxis;

protected:
    UPROPERTY(SaveGame, Transient)
    FVector OrbitAxis;

    UPROPERTY(SaveGame, Transient)
    FVector OrbitAxisCreative;

private:
    UPROPERTY(SaveGame, Transient)
    FVector InitialOrbitOffset;

    UPROPERTY(SaveGame, Transient)
    FVector InitialOrbitAxis;

    UPROPERTY(SaveGame, Transient)
    FTransform InitialTransform;

    UPROPERTY(SaveGame, Transient)
    float LastCalculatedNormalizedDayTime;

    UPROPERTY(Replicated, SaveGame, Transient)
    float DayTimeBias;

    UPROPERTY(SaveGame, Transient)
    float LastSetOrbitAxisRotation;

public:
    ASolarBody();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetOrbitAxisRotation(float rads);

    UFUNCTION(BlueprintCallable)
    void SetNormalizedDayTime(float dayTime);

    UFUNCTION(BlueprintCallable)
    void SetDayLength(float newDayLength);

    UFUNCTION(BlueprintCallable)
    void SetBodyTransform(const FTransform &Transform);

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION()
    void OnRep_OrbitAxis();

    UFUNCTION()
    void OnLocalPlayerPlanetSelectionEnd();

    UFUNCTION()
    void OnLocalPlayerPlanetSelectionBegin(ASolarBody *homeSolarBody);

    UFUNCTION()
    void OnLocalPlayerLocalSolarBodyChanged(ASolarBody *newLocalSolarBody);

protected:
    UFUNCTION()
    void OnCreativeModeEnabledChanged(bool CreativeModeEnabled);

public:
    UFUNCTION(BlueprintPure)
    USceneComponent *GetProxyComponent();

    UFUNCTION(BlueprintPure)
    FVector GetProxyCenter() const;

    UFUNCTION(BlueprintPure)
    FVector GetOrbitAxis();

    UFUNCTION(BlueprintPure)
    float GetNormalizedDayTime() const;

    UFUNCTION(BlueprintPure)
    float GetLastOrbitAxisRotation() const;

    UFUNCTION(BlueprintPure)
    FRotator GetDayRotationOffset() const;

    UFUNCTION(BlueprintPure)
    USceneComponent *GetCenterComponent();

    UFUNCTION(BlueprintPure)
    FVector GetCenter() const;

    UFUNCTION(BlueprintPure)
    FTransform GetBodyTransform() const;

    UFUNCTION(BlueprintPure)
    bool CanBeVisitedByPlayer() const;
};