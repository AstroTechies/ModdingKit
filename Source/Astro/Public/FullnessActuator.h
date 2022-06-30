#pragma once
#include "CoreMinimal.h"
#include "EFullnessActuatorResponseMode.h"
#include "PhysicalItem.h"
#include "SignalDelegate.h"
#include "EFullnessActuatorEventType.h"
#include "FullnessActuatorResponseModeStrings.h"
#include "FullnessActuator.generated.h"

class UActuatorComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API AFullnessActuator : public APhysicalItem
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnFullnessResponseModeChanged;

protected:
    UPROPERTY(Export, VisibleAnywhere)
    UActuatorComponent *ActuatorComponent;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_TargetItem)
    TWeakObjectPtr<APhysicalItem> TargetItem;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_MostRecentEvent, meta = (AllowPrivateAccess = true))
    EFullnessActuatorEventType MostRecentEvent;

    UPROPERTY(SaveGame)
    uint8 bWasEmpty : 1;

    UPROPERTY(SaveGame)
    uint8 bWasFull : 1;

    UPROPERTY(SaveGame)
    uint8 EventTypeFlags;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_FullnessResponseMode, meta = (AllowPrivateAccess = true))
    EFullnessActuatorResponseMode FullnessResponseMode;

    UPROPERTY(EditDefaultsOnly)
    FText SubtitleFormatText;

    UPROPERTY(EditDefaultsOnly)
    FText DescriptionFormatText;

    UPROPERTY(EditDefaultsOnly)
    FText DescriptionText;

    UPROPERTY(EditDefaultsOnly)
    FText StatusFormatText;

    UPROPERTY(EditDefaultsOnly)
    FText SlottedStatusString;

    UPROPERTY(EditDefaultsOnly)
    FText InvalidTargetStatusString;

    UPROPERTY(EditDefaultsOnly)
    TArray<FFullnessActuatorResponseModeStrings> ResponseModeStrings;

public:
    AFullnessActuator();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

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
