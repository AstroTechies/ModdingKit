#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "SignalDelegate.h"
#include "EFullnessActuatorEventType.h"
#include "EFullnessActuatorResponseMode.h"
#include "FullnessActuatorResponseModeStrings.h"
#include "FullnessActuator.generated.h"

class UActuatorComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AFullnessActuator : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnFullnessResponseModeChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActuatorComponent* ActuatorComponent;
    
    UPROPERTY(EditAnywhere, Transient, ReplicatedUsing=OnRep_TargetItem)
    TWeakObjectPtr<APhysicalItem> TargetItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MostRecentEvent, meta=(AllowPrivateAccess=true))
    EFullnessActuatorEventType MostRecentEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bWasEmpty: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bWasFull: 1;
    
    UPROPERTY(EditAnywhere, SaveGame)
    uint8 EventTypeFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_FullnessResponseMode, meta=(AllowPrivateAccess=true))
    EFullnessActuatorResponseMode FullnessResponseMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SubtitleFormatText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DescriptionFormatText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DescriptionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StatusFormatText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SlottedStatusString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InvalidTargetStatusString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFullnessActuatorResponseModeStrings> ResponseModeStrings;
    
public:
    AFullnessActuator();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnRep_TargetItem();
    
    UFUNCTION()
    void OnRep_MostRecentEvent();
    
    UFUNCTION()
    void OnRep_FullnessResponseMode();
    
    UFUNCTION()
    void HandleReleasedFromSlot(bool NewOwner);
    
    UFUNCTION()
    void HandlePlacedInSlot();
    
    UFUNCTION()
    void AuthorityRespondToMotionStateChange();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityCycleFullnessResponseMode();
    
};

