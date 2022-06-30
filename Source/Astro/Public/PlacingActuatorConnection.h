#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotConnection.h"
#include "TooltipWidgetDisplayData.h"
#include "SignalDelegate.h"
#include "TooltipStatusDelegateDelegate.h"
#include "SourceRerouteNode.h"
#include "UObject/NoExportTypes.h"
#include "PlacingActuatorConnection.generated.h"

class UStaticMesh;
class UMaterialInstanceDynamic;
class UItemList;
class AItemSlot;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API APlacingActuatorConnection : public ASlotConnection
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *RerouteNodeMesh;

    UPROPERTY(EditDefaultsOnly)
    float ActuatorConnectorPlacementOffset;

    UPROPERTY(EditDefaultsOnly)
    float RerouteNodePlacementOffset;

    UPROPERTY(EditDefaultsOnly)
    int32 MaxActuatorCablesPerSlot;

    UPROPERTY(EditDefaultsOnly)
    int32 ActuateFlashCount;

    UPROPERTY(EditDefaultsOnly)
    float ActuateFlashDuration;

    UPROPERTY(EditDefaultsOnly)
    FTooltipWidgetDisplayData PlacedRerouteNodeTooltip;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AItemSlot> ActuatorPinSlotClass;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UItemList> AttachItemTypeBlacklist;

protected:
    UPROPERTY(BlueprintAssignable)
    FSignal OnLocalClientTookOwnership;

    UPROPERTY(BlueprintAssignable)
    FTooltipStatusDelegate OnTooltipStatusChanged;

    UPROPERTY()
    UMaterialInstanceDynamic *ConnectorMaterial;

    UPROPERTY(ReplicatedUsing = OnRep_SourceRerouteNode)
    FSourceRerouteNode SourceRerouteNode;

public:
    APlacingActuatorConnection();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerPlaceRerouteNode(UPrimitiveComponent *Component, const FVector Location, const FVector Normal);

    UFUNCTION()
    void RefreshTooltipStatus();

    UFUNCTION()
    void OnUsePressed();

    UFUNCTION()
    void OnRep_SourceRerouteNode();

    UFUNCTION(NetMulticast, Reliable)
    void MulticastPlayBreakAudio();

    UFUNCTION()
    void InitializeSourceSlot();
};
