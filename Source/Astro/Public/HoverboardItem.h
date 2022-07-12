#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include "PhysicalItem.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "HoverboardItem.generated.h"

class UPowerComponent;
class UHoverboardMovementOverrideComponent;
class AAstroCharacter;

UCLASS(Blueprintable)
class ASTRO_API AHoverboardItem : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UHoverboardMovementOverrideComponent* HoverboardMovementOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DoubleJumpInputWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    FGuid Guid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_HoverboardActive, meta=(AllowPrivateAccess=true))
    uint8 bHoverboardActive: 1;
    
public:
    AHoverboardItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnUpdateHoverboardOrientation();
    
private:
    UFUNCTION()
    void OnRep_HoverboardActive();
    
    UFUNCTION()
    void OnMovementOverrideTick(float DeltaTime);
    
public:
    UFUNCTION()
    void OnJumpStarted();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnHoverboardActivated(bool Activated);
    
private:
    UFUNCTION()
    void OnHasPowerAvailableChanged(bool HasAvailablePower);
    
    UFUNCTION()
    void OnEndOperation();
    
    UFUNCTION()
    void OnClientActionPressed();
    
    UFUNCTION()
    void OnAuthorityOverrideRemoved();
    
    UFUNCTION()
    void OnAuthorityOverrideAdded();
    
    UFUNCTION()
    void HandleRemovedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
    UFUNCTION()
    void HandleOnSpawnedInSlot();
    
public:
    UFUNCTION(BlueprintPure)
    bool GetHoverboardActive();
    
    UFUNCTION(BlueprintCallable)
    FRotator CalculateHoverboardRotation(float minVelocitySize, float maxPitchDegrees, float maxRollDegrees, float maxTurnDegrees, float& outRollDegree);
    
};

