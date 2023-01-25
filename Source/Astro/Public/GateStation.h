#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "SolarBody.h"
#include "GateStation.generated.h"

class AActor;
class UActorEntityLinkComponent;
class UActorGateObjectComponent;
class UClickableComponent;
class USceneComponent;
class USphereComponent;
class UStaticMeshComponent;
class UStationGateObjectIndicatorDefinitions;
class UTooltipComponent;

UCLASS(Blueprintable)
class ASTRO_API AGateStation : public ASolarBody {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StationMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TeleporterPositioningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ClickCollisionSphere;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ProxyMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ProxyRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ProxyMeshScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator OrbitalRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorGateObjectComponent* GateObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStationGateObjectIndicatorDefinitions* StationIndicatorDefinitions;
    
public:
    AGateStation();
    UFUNCTION(BlueprintCallable)
    void OnOutroCinematicStarted();
    
    UFUNCTION(BlueprintCallable)
    void OnOutroCinematicCompleted();
    
    UFUNCTION(BlueprintCallable)
    void OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeLandingZones();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleActualVisibilityChanged(bool bIsVisible);
    
};

