#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "StreamingPowerCableVisualizationData.h"
#include "ActorStreamingPowerCableComponent.generated.h"

class AActor;
class UActorStreamingPowerCableComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorStreamingPowerCableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateStreamingPowerCableVisualizationData, const FStreamingPowerCableVisualizationData&, PowerCableVisualizationData);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConnectionInterrupted, UActorStreamingPowerCableComponent*, powerCable, bool, bInterrupted);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateStreamingPowerCableVisualizationData OnUpdateStreamingPowerCableVisualizationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VisualizationData, meta=(AllowPrivateAccess=true))
    FStreamingPowerCableVisualizationData StreamingPowerCableVisualizationData;
    
    UActorStreamingPowerCableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetDirectionalConnectionSplitRatio(float ratio);
    
    UFUNCTION(BlueprintCallable)
    void OnSelfDestroyed(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_VisualizationData();
    
public:
    UFUNCTION(BlueprintCallable)
    void MakeSlotConnection(FSlotReference From, FSlotReference To);
    
    UFUNCTION(BlueprintCallable)
    void Disconnect();
    
};

