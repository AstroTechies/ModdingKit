#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StreamingPowerNodeVisualizationData.h"
#include "ActorStreamingPowerNodeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorStreamingPowerNodeComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateStreamingNodePowerVisualization, const FStreamingPowerNodeVisualizationData&, VisualizationData);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateStreamingNodePowerVisualization OnUpdatePowerVisualization;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_VisualizationData, meta=(AllowPrivateAccess=true))
    FStreamingPowerNodeVisualizationData PowerVisualizationDataReplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CanPropagateDirectionalConnectionSwaps: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSkipPacketLoopProtectionCheck: 1;
    
    UActorStreamingPowerNodeComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void OnRep_VisualizationData();
    
};

