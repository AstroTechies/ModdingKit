#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineBaseTypes.h"
#include "ESplineConnectionState.h"
#include "SlotReference.h"
#include "SplinePostSlot.h"
#include "StreamingPowerNodeVisualizationData.h"
#include "SplinePost.generated.h"

class UActuatorComponent;
class UMaterialInstanceDynamic;
class UPrimitiveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API USplinePost : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> SplineSlots;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* OverlapFrontComponentOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* OverlapBackComponentOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSplinePostSlot> FrontBackSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GaugeDynamicMaterialIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* GaugeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsMovable, meta=(AllowPrivateAccess=true))
    uint8 bIsMovable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasBeenInitialized: 1;
    
public:
    USplinePost(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetIsSnappedToSpline();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsMovable() const;
    
public:
    UFUNCTION()
    void OnAsyncMapLoadStarted(const FURL& URL);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetConnectionState(ESplineConnectionState ConnectionState);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleSplineNetworkCreated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandlePowerChanged(const FStreamingPowerNodeVisualizationData& powerData);
    
    UFUNCTION(BlueprintCallable)
    void HandlePickedUp(bool isPhysicalMovement);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleIsAttachedToTerrainChanged();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandleDroppedDelayed();
    
    UFUNCTION(BlueprintCallable)
    void HandleDropped(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void HandleDeformCompleted(float DensityDelta);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityHandleOxygenChanged(bool hasOxygen);
    
};

