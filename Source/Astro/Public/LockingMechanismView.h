#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "SignalDelegate.h"
#include "LockChangedEventMetadata.h"
#include "LockingMechanismView.generated.h"

class ULockingMechanismDefinition;
class ULockingMechanism;

UCLASS(Blueprintable)
class ASTRO_API ULockingMechanismView : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOpenChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsOpen, meta=(AllowPrivateAccess=true))
    uint8 bIsOpen: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULockingMechanism* LinkedLockingMechanism;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULockingMechanismDefinition* Definition;
    
    ULockingMechanismView();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION()
    void OnRep_IsOpen();
    
    UFUNCTION()
    void OnOpenStateChanged(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData);
    
};

