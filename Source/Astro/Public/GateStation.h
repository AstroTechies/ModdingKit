#pragma once
#include "CoreMinimal.h"
#include "SolarBody.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "GateStation.generated.h"

class UStaticMeshComponent;
class UClickableComponent;
class USceneComponent;
class UTooltipComponent;
class USphereComponent;
class UActorGateObjectComponent;
class UActorEntityLinkComponent;
class UStationGateObjectIndicatorDefinitions;
class AActor;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AGateStation : public ASolarBody
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, VisibleAnywhere)
    UStaticMeshComponent *StationMesh;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    USceneComponent *TeleporterPositioningComponent;

    UPROPERTY(Export, VisibleAnywhere)
    UClickableComponent *ClickableComponent;

    UPROPERTY(Export, VisibleAnywhere)
    UTooltipComponent *TooltipComponent;

    UPROPERTY(Export)
    USphereComponent *ClickCollisionSphere;

    UPROPERTY(Export)
    UStaticMeshComponent *ProxyMesh;

    UPROPERTY(Export)
    USceneComponent *ProxyRoot;

    UPROPERTY(EditDefaultsOnly)
    float ProxyMeshScale;

    UPROPERTY(EditDefaultsOnly)
    FRotator OrbitalRotationOffset;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorGateObjectComponent *GateObjectComponent;

    UPROPERTY(Export, VisibleAnywhere)
    UActorEntityLinkComponent *EntityLinkComponent;

    UPROPERTY(EditAnywhere)
    UStationGateObjectIndicatorDefinitions *StationIndicatorDefinitions;

public:
    AGateStation();
    UFUNCTION()
    void OnOutroCinematicStarted();

    UFUNCTION()
    void OnOutroCinematicCompleted();

    UFUNCTION()
    void OnClickedInSolarView(AActor *TouchedActor, FKey ButtonPressed);

    UFUNCTION(BlueprintImplementableEvent)
    void InitializeLandingZones();
};
