#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GateObject.generated.h"

class UActorGateObjectComponent;
class UStaticMeshComponent;
class USolarSystem;
class USceneComponent;
class UActorEntityLinkComponent;
class ASolarBody;

UCLASS(Blueprintable, Abstract)
class ASTRO_API AGateObject : public AActor
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *StaticMesh;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    USceneComponent *TeleporterPositioningComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorGateObjectComponent *GateObjectComponent;

    UPROPERTY(Export, VisibleAnywhere)
    UActorEntityLinkComponent *EntityLinkComponent;

    UPROPERTY(Transient)
    ASolarBody *LocalSolarBody;

public:
    AGateObject();

protected:
    UFUNCTION()
    void OnSolarSystemInitialized(USolarSystem *SolarSystem);

    UFUNCTION()
    void OnLocalPlayerChangedLocalSolarBody(ASolarBody *playerLocalSolarBody);
};
