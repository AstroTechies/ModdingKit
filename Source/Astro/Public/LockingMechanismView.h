#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "LockChangedEventMetadata.h"
#include "SignalDelegate.h"
#include "LockingMechanismView.generated.h"

class ULockingMechanism;
class ULockingMechanismDefinition;

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
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsOpen();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenStateChanged(ULockingMechanism* LockingMechanism, const FLockChangedEventMetadata& EventData);
    
};

