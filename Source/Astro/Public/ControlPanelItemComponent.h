#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControlPanelReadyEventDelegate.h"
#include "ControlPanelItemComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlPanelItemComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FControlPanelReadyEvent OnControlPanelAvailable;

    UControlPanelItemComponent();
};
