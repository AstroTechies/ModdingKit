#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "ControlPanel.h"
#include "EGateObjectControlPanelContext.h"
#include "GateObjectControlNode.h"
#include "GateObjectReference.h"
#include "IndicatorMeshDefinition.h"
#include "GateObjectControlPanel.generated.h"

class UMaterialInterface;
class UPrimitiveComponent;
class USceneComponent;
class USolarSystem;
class UStaticMeshComponent;
class UTooltipComponent;

UCLASS(Abstract, Blueprintable)
class ASTRO_API AGateObjectControlPanel : public AControlPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D NodeTooltipAnchorOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipOwnerNodeTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipActiveNodeTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipInactiveNodeTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipEquatorNodeSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipNorthPoleNodeSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipSouthPoleNodeSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor TooltipBadgeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DefaultInertIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DefaultActiveIndicatorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIndicatorMeshDefinition PlayerMeshDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenteredNodeRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChamberIndicatorOffsetDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SolarSystemViewRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StationControlNodeOffsetInPlanetView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StationControlNodeOffsetInSolarView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator SolarViewRootRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleInterpolationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGateObjectControlPanelContext CurrentContext;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGateObjectControlNode> ControlNodes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedControlNodeIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentLocationControlNodeIndex, meta=(AllowPrivateAccess=true))
    int32 CurrentLocationControlNodeIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* CrackedRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ControlNodeRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SunIndicatorComponent;
    
public:
    AGateObjectControlPanel();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetContext(EGateObjectControlPanelContext newContext);
    
    UFUNCTION(BlueprintCallable)
    void SelectControlNode(int32 controlNodeIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSolarSystemInitialized(USolarSystem* SolarSystem);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSelectedControlNodeGateObjectActivated();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSelectedControlNodeChanged();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentLocationControlNodeIndex();
    
    UFUNCTION(BlueprintCallable)
    void OnGateStationSpawned();
    
    UFUNCTION(BlueprintCallable)
    void OnGateObjectActivated(const FGateObjectReference& ActivatedGateObjectRef);
    
    UFUNCTION(BlueprintCallable)
    void OnControlNodeEndCursorOver(UPrimitiveComponent* hoveredControlNodeMesh);
    
    UFUNCTION(BlueprintCallable)
    void OnControlNodeClicked(UPrimitiveComponent* clickedControlNodeMesh, FKey ButtonPressed);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnControlNodeCenteringInterpolationFinished();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnControlNodeBeginCursorOver(UPrimitiveComponent* hoveredControlNodeMesh);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsControlNodeGateObjectActivated(int32 controlNodeIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleControlNodeEndHover(const FGateObjectControlNode& hoveredControlNode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleControlNodeClick(const FGateObjectControlNode& clickedControlNode);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleControlNodeBeginHover(const FGateObjectControlNode& hoveredControlNode);
    
    UFUNCTION(BlueprintCallable)
    void CenterControlNodeInView(int32 controlNodeIndex, float InterpolationTime);
    
};

