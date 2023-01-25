#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "SolarBody.h"
#include "SolarControlRoom.generated.h"

class AActor;
class UClickableComponent;
class USceneComponent;
class USolarSystem;
class USphereComponent;
class UStaticMeshComponent;
class UTooltipComponent;

UCLASS(Blueprintable)
class ASTRO_API ASolarControlRoom : public ASolarBody {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GateStationOrbitDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GateStationOrbitDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector GateStationOrbitAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UnlockingMissionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SelectedAudioEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ControlRoomMesh;
    
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
    
public:
    ASolarControlRoom();
    UFUNCTION(BlueprintCallable)
    void UnlockSolarControlRoom();
    
    UFUNCTION(BlueprintCallable)
    void SetActualVisibility(bool bIsVisible);
    
    UFUNCTION(BlueprintCallable)
    void OnMissionsInitialized();
    
    UFUNCTION(BlueprintCallable)
    void OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeLandingZones();
    
    UFUNCTION(BlueprintCallable)
    void InitializeForSolarSystem(USolarSystem* SolarSystem);
    
    UFUNCTION(BlueprintCallable)
    void HandleMissionComplete(FName missionId);
    
    UFUNCTION(BlueprintCallable)
    void HandleCreativeModeEnabledChanged(bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleActualVisibilityChanged(bool bIsVisible);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsUnlocked();
    
};

