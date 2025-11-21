#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "PhysicalItem.h"
#include "HoverboardItem.generated.h"

class AAstroCharacter;
class UHoverboardMovementOverrideComponent;
class UPowerComponent;

UCLASS(Blueprintable)
class ASTRO_API AHoverboardItem : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHoverboardMovementOverrideComponent* HoverboardMovementOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoubleJumpInputWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_HoverboardActive, meta=(AllowPrivateAccess=true))
    uint8 bHoverboardActive: 1;
    
public:
    AHoverboardItem(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateHoverboardOrientation();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_HoverboardActive();
    
    UFUNCTION(BlueprintCallable)
    void OnMovementOverrideTick(float DeltaTime);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnJumpStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHoverboardActivated(bool Activated);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnHasPowerAvailableChanged(bool HasAvailablePower);
    
    UFUNCTION(BlueprintCallable)
    void OnEndOperation();
    
    UFUNCTION(BlueprintCallable)
    void OnClientActionPressed();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityOverrideRemoved();
    
    UFUNCTION(BlueprintCallable)
    void OnAuthorityOverrideAdded();
    
    UFUNCTION(BlueprintCallable)
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void HandlePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnSpawnedInSlot();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHoverboardActive();
    
    UFUNCTION(BlueprintCallable)
    FRotator CalculateHoverboardRotation(float minVelocitySize, float maxPitchDegrees, float maxRollDegrees, float maxTurnDegrees, float& outRollDegree);
    
};

