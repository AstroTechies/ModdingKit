#pragma once
#include "CoreMinimal.h"
#include "StreamingPowerNodeVisualizationData.h"
#include "Components/ActorComponent.h"
#include "ActorStreamingPowerNodeComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorStreamingPowerNodeComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateStreamingNodePowerVisualization, const FStreamingPowerNodeVisualizationData &, VisualizationData);

    UPROPERTY(BlueprintAssignable)
    FUpdateStreamingNodePowerVisualization OnUpdatePowerVisualization;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_VisualizationData, meta = (AllowPrivateAccess = true))
    FStreamingPowerNodeVisualizationData PowerVisualizationDataReplicated;

    UPROPERTY(EditAnywhere)
    uint8 CanPropagateDirectionalConnectionSwaps : 1;

    UPROPERTY(EditAnywhere)
    uint8 bSkipPacketLoopProtectionCheck : 1;

    UActorStreamingPowerNodeComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_VisualizationData();
};
