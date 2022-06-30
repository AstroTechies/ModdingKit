#pragma once
#include "CoreMinimal.h"
#include "IndicatorMeshDefinition.h"
#include "ControlPanel.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GateObjectReference.h"
#include "UObject/NoExportTypes.h"
#include "EGateObjectControlPanelContext.h"
#include "GateObjectControlNode.h"
#include "GateObjectControlPanel.generated.h"

class UTooltipComponent;
class UMaterialInterface;
class USolarSystem;
class USceneComponent;
class UStaticMeshComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, Abstract)
class ASTRO_API AGateObjectControlPanel : public AControlPanel
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    FVector2D NodeTooltipAnchorOffset;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipOwnerNodeTitle;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipActiveNodeTitle;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipInactiveNodeTitle;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipEquatorNodeSubtitle;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipNorthPoleNodeSubtitle;

    UPROPERTY(EditDefaultsOnly)
    FText TooltipSouthPoleNodeSubtitle;

    UPROPERTY(EditDefaultsOnly)
    FLinearColor TooltipBadgeColor;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *DefaultInertIndicatorMaterial;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *DefaultActiveIndicatorMaterial;

    UPROPERTY(EditDefaultsOnly)
    FIndicatorMeshDefinition PlayerMeshDefinition;

    UPROPERTY(EditDefaultsOnly)
    float CenteredNodeRotationOffset;

    UPROPERTY(EditDefaultsOnly)
    float ChamberIndicatorOffsetDistance;

    UPROPERTY(EditDefaultsOnly)
    float SolarSystemViewRadius;

    UPROPERTY(EditDefaultsOnly)
    FVector StationControlNodeOffsetInPlanetView;

    UPROPERTY(EditDefaultsOnly)
    FVector StationControlNodeOffsetInSolarView;

    UPROPERTY(EditDefaultsOnly)
    FRotator SolarViewRootRotationOffset;

    UPROPERTY(EditDefaultsOnly)
    float ScaleInterpolationDuration;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    EGateObjectControlPanelContext CurrentContext;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FGateObjectControlNode> ControlNodes;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 SelectedControlNodeIndex;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_CurrentLocationControlNodeIndex, meta = (AllowPrivateAccess = true))
    int32 CurrentLocationControlNodeIndex;

    UPROPERTY(Export)
    USceneComponent *CrackedRoot;

    UPROPERTY(Export)
    USceneComponent *ControlNodeRoot;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UTooltipComponent *TooltipComponent;

    UPROPERTY(Export, Transient)
    UStaticMeshComponent *SunIndicatorComponent;

public:
    AGateObjectControlPanel();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetContext(EGateObjectControlPanelContext newContext);

    UFUNCTION(BlueprintCallable)
    void SelectControlNode(int32 controlNodeIndex);

protected:
    UFUNCTION()
    void OnSolarSystemInitialized(USolarSystem *SolarSystem);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnSelectedControlNodeGateObjectActivated();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSelectedControlNodeChanged();

protected:
    UFUNCTION()
    void OnRep_CurrentLocationControlNodeIndex();

    UFUNCTION()
    void OnGateStationSpawned();

    UFUNCTION()
    void OnGateObjectActivated(const FGateObjectReference &ActivatedGateObjectRef);

    UFUNCTION()
    void OnControlNodeEndCursorOver(UPrimitiveComponent *hoveredControlNodeMesh);

    UFUNCTION()
    void OnControlNodeClicked(UPrimitiveComponent *clickedControlNodeMesh, FKey ButtonPressed);

public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnControlNodeCenteringInterpolationFinished();

protected:
    UFUNCTION()
    void OnControlNodeBeginCursorOver(UPrimitiveComponent *hoveredControlNodeMesh);

public:
    UFUNCTION(BlueprintPure)
    bool IsControlNodeGateObjectActivated(int32 controlNodeIndex) const;

    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeEndHover(const FGateObjectControlNode &hoveredControlNode);

    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeClick(const FGateObjectControlNode &clickedControlNode);

    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeBeginHover(const FGateObjectControlNode &hoveredControlNode);

    UFUNCTION(BlueprintCallable)
    void CenterControlNodeInView(int32 controlNodeIndex, float InterpolationTime);
};
