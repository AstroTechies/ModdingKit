#pragma once
#include "CoreMinimal.h"
#include "SolarBody.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "GateStation.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class USphereComponent;
class UClickableComponent;
class UActorGateObjectComponent;
class UTooltipComponent;
class AActor;
class UActorEntityLinkComponent;
class UStationGateObjectIndicatorDefinitions;

UCLASS(Blueprintable)
class ASTRO_API AGateStation : public ASolarBody {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StationMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* TeleporterPositioningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USphereComponent* ClickCollisionSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ProxyMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* ProxyRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProxyMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator OrbitalRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorGateObjectComponent* GateObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStationGateObjectIndicatorDefinitions* StationIndicatorDefinitions;
    
public:
    AGateStation();
    UFUNCTION()
    void OnOutroCinematicStarted();
    
    UFUNCTION()
    void OnOutroCinematicCompleted();
    
    UFUNCTION()
    void OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed);
    
    UFUNCTION(BlueprintImplementableEvent)
    void InitializeLandingZones();
    
};

