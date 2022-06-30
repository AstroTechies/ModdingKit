#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "SolarBodyRelativeTransforms.h"
#include "UObject/NoExportTypes.h"
#include "DayNight.generated.h"

class UAstroSaveCustomArchiveProxy;
class ASolarBody;
class USkyLightComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ADayNight : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor SpaceAmbientColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SpaceAmbientIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SolarSystemSpeed;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    float SkyVisibility;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ServerCorrectionTime;

    UPROPERTY(EditAnywhere)
    FLinearColor SpaceFakeBounce;

    UPROPERTY(Transient)
    ASolarBody *LockLocalBody;

protected:
    UPROPERTY(Transient)
    TArray<ASolarBody *> SolarBodies;

    UPROPERTY(Transient)
    TMap<ASolarBody *, FSolarBodyRelativeTransforms> SolarBodyReleativeTransforms;

    UPROPERTY(Export, VisibleDefaultsOnly)
    USkyLightComponent *SkyLight;

private:
    UPROPERTY(Replicated, SaveGame, Transient)
    double ServerTimeStamp;

    UPROPERTY(SaveGame, Transient)
    FTransform InitialTransform;

    UPROPERTY(SaveGame, Transient)
    float TargetSkyVisibility;

public:
    ADayNight();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);
};
