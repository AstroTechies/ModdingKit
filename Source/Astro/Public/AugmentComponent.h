#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "EAugmentProperty.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "AugmentComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAugmentComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAugmentProperty, float> AugmentPropertyMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicated_AugmentEquipped, meta=(AllowPrivateAccess=true))
    bool AugmentIsEquipped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentEquipped;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentUnequipped;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicated_AugmentActive, meta=(AllowPrivateAccess=true))
    bool AugmentIsActive;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentActivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentDeactivated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicated_AugmentEnabled, meta=(AllowPrivateAccess=true))
    bool AugmentIsEnabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAugmentPropertyChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SuppressClickableWhileDeactivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle ReactivationTimer;
    
public:
    UAugmentComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void UnblockReactivation();
    
public:
    UFUNCTION()
    void SetPowerDrawEnabled(bool drawEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetAugmentEquipped(bool equipped);
    
    UFUNCTION(BlueprintCallable)
    bool SetAugmentEnabled(bool IsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SetAugmentActive(bool Active);
    
private:
    UFUNCTION()
    void PhysicalItemUnslotted(bool NewOwner);
    
public:
    UFUNCTION()
    void OnReplicated_AugmentEquipped();
    
    UFUNCTION()
    void OnReplicated_AugmentEnabled();
    
    UFUNCTION()
    void OnReplicated_AugmentActive();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentUnequipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentDisabled();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentDeactivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AugmentActivated();
    
};

