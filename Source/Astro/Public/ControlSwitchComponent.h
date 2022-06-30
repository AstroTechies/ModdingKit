#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "ControlSwitchComponent.generated.h"

class UComponentDelegateWrapper;
class UChildActorComponent;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlSwitchComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UChildActorComponent *> ControlButtons;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> Slots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference ActiveControlSlot;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 ActiveControlIndex;

private:
    UPROPERTY()
    TArray<UComponentDelegateWrapper *> ClickDelegates;

public:
    UControlSwitchComponent();

private:
    UFUNCTION()
    void SetControlledSlot(int32 Index);

    UFUNCTION()
    void OnSwitchClicked(USceneComponent *Component);
};
