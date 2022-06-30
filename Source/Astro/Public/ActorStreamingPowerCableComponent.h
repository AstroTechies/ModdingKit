#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StreamingPowerCableVisualizationData.h"
#include "SlotReference.h"
#include "ActorStreamingPowerCableComponent.generated.h"

class AActor;
class UActorStreamingPowerCableComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorStreamingPowerCableComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateStreamingPowerCableVisualizationData, const FStreamingPowerCableVisualizationData &, PowerCableVisualizationData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConnectionInterrupted, UActorStreamingPowerCableComponent *, powerCable, bool, bInterrupted);

    UPROPERTY(BlueprintAssignable)
    FUpdateStreamingPowerCableVisualizationData OnUpdateStreamingPowerCableVisualizationData;

    UPROPERTY(ReplicatedUsing = OnRep_VisualizationData)
    FStreamingPowerCableVisualizationData StreamingPowerCableVisualizationData;

    UActorStreamingPowerCableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetDirectionalConnectionSplitRatio(float ratio);

    UFUNCTION()
    void OnSelfDestroyed(AActor *Actor);

private:
    UFUNCTION()
    void OnRep_VisualizationData();

public:
    UFUNCTION(BlueprintCallable)
    void MakeSlotConnection(FSlotReference From, FSlotReference To);

    UFUNCTION(BlueprintCallable)
    void Disconnect();
};
