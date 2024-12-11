#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "ControlSwitchComponent.generated.h"

class UChildActorComponent;
class UComponentDelegateWrapper;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UControlSwitchComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UChildActorComponent*> ControlButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ActiveControlSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveControlIndex;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UComponentDelegateWrapper*> ClickDelegates;
    
public:
    UControlSwitchComponent(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void SetControlledSlot(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void OnSwitchClicked(USceneComponent* Component);
    
};

