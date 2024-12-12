#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ControlPanelReadyEventDelegate.h"
#include "ControlPanelItemComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UControlPanelItemComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlPanelReadyEvent OnControlPanelAvailable;
    
    UControlPanelItemComponent(const FObjectInitializer& ObjectInitializer);

};

