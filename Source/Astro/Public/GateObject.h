#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "GateObject.generated.h"

class ASolarBody;
class USceneComponent;
class UStaticMeshComponent;
class UActorGateObjectComponent;
class UActorEntityLinkComponent;
class USolarSystem;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AGateObject : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* TeleporterPositioningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorGateObjectComponent* GateObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASolarBody* LocalSolarBody;
    
public:
    AGateObject();
protected:
    UFUNCTION()
    void OnSolarSystemInitialized(USolarSystem* SolarSystem);
    
    UFUNCTION()
    void OnLocalPlayerChangedLocalSolarBody(ASolarBody* playerLocalSolarBody);
    
};

