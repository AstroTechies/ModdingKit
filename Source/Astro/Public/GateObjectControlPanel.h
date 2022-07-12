#pragma once
#include "CoreMinimal.h"
#include "EGateObjectControlPanelContext.h"
#include "ControlPanel.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "IndicatorMeshDefinition.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
#include "GateObjectControlNode.h"
#include "GateObjectReference.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "GateObjectControlPanel.generated.h"

class UMaterialInterface;
class USceneComponent;
class UTooltipComponent;
class UStaticMeshComponent;
class USolarSystem;
class UPrimitiveComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* CrackedRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* ControlNodeRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* SunIndicatorComponent;
    
public:
    AGateObjectControlPanel();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetContext(EGateObjectControlPanelContext newContext);
    
    UFUNCTION(BlueprintCallable)
    void SelectControlNode(int32 controlNodeIndex);
    
protected:
    UFUNCTION()
    void OnSolarSystemInitialized(USolarSystem* SolarSystem);
    
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
    void OnGateObjectActivated(const FGateObjectReference& ActivatedGateObjectRef);
    
    UFUNCTION()
    void OnControlNodeEndCursorOver(UPrimitiveComponent* hoveredControlNodeMesh);
    
    UFUNCTION()
    void OnControlNodeClicked(UPrimitiveComponent* clickedControlNodeMesh, FKey ButtonPressed);
    
public:
    UFUNCTION(BlueprintImplementableEvent)
    void OnControlNodeCenteringInterpolationFinished();
    
protected:
    UFUNCTION()
    void OnControlNodeBeginCursorOver(UPrimitiveComponent* hoveredControlNodeMesh);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsControlNodeGateObjectActivated(int32 controlNodeIndex) const;
    
    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeEndHover(const FGateObjectControlNode& hoveredControlNode);
    
    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeClick(const FGateObjectControlNode& clickedControlNode);
    
    UFUNCTION(BlueprintImplementableEvent)
    void HandleControlNodeBeginHover(const FGateObjectControlNode& hoveredControlNode);
    
    UFUNCTION(BlueprintCallable)
    void CenterControlNodeInView(int32 controlNodeIndex, float InterpolationTime);
    
};

