#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GateObject.generated.h"

class ASolarBody;
class UActorEntityLinkComponent;
class UActorGateObjectComponent;
class USceneComponent;
class USolarSystem;
class UStaticMeshComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AGateObject : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TeleporterPositioningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorGateObjectComponent* GateObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorEntityLinkComponent* EntityLinkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASolarBody* LocalSolarBody;
    
public:
    AGateObject();
protected:
    UFUNCTION(BlueprintCallable)
    void OnSolarSystemInitialized(USolarSystem* SolarSystem);
    
    UFUNCTION(BlueprintCallable)
    void OnLocalPlayerChangedLocalSolarBody(ASolarBody* playerLocalSolarBody);
    
};

