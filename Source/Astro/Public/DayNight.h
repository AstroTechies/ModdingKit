#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "Components/SkyLightComponent.h"
#include "GameFramework/Actor.h"
#include "SolarBodyRelativeTransforms.h"
#include "DayNight.generated.h"

class ASolarBody;
class UAstroSaveCustomArchiveProxy;
class USkyLightComponent;

UCLASS(Blueprintable)
class ASTRO_API ADayNight : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SpaceAmbientColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpaceAmbientIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SolarSystemSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float SkyVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ServerCorrectionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor SpaceFakeBounce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASolarBody* LockLocalBody;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASolarBody*> SolarBodies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<ASolarBody*, FSolarBodyRelativeTransforms> SolarBodyReleativeTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkyLightComponent* SkyLight;
    
private:
    UPROPERTY(EditAnywhere, Replicated, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    double ServerTimeStamp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FTransform InitialTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    float TargetSkyVisibility;
    
public:
    ADayNight();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
};

