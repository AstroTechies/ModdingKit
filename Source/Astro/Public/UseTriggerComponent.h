#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "UseTriggerComponent.generated.h"

class AActor;
class UItemList;
class APlayController;
class UPrimitiveComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UUseTriggerComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 bTriggeredByPlayers : 1;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> TriggerItems;

    UPROPERTY(EditDefaultsOnly)
    TArray<FComponentReference> TriggerVolumes;

    UPROPERTY(EditDefaultsOnly)
    float CooldownTime;

    UPROPERTY()
    UItemList *TriggerItemList;

    UPROPERTY()
    APlayController *CurrentInstigator;

public:
    UUseTriggerComponent();

protected:
    UFUNCTION()
    void OnTriggerVolumeOverlapped(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnCooldownCompleted();
};
