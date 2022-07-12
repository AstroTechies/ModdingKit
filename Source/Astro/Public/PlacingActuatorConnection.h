#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotConnection.h"
#include "TooltipWidgetDisplayData.h"
#include "SignalDelegate.h"
#include "TooltipStatusDelegateDelegate.h"
#include "SourceRerouteNode.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "PlacingActuatorConnection.generated.h"

class UStaticMesh;
class UMaterialInstanceDynamic;
class UItemList;
class AItemSlot;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API APlacingActuatorConnection : public ASlotConnection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* RerouteNodeMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActuatorConnectorPlacementOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RerouteNodePlacementOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxActuatorCablesPerSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActuateFlashCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActuateFlashDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData PlacedRerouteNodeTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItemSlot> ActuatorPinSlotClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemList> AttachItemTypeBlacklist;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLocalClientTookOwnership;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipStatusDelegate OnTooltipStatusChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ConnectorMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SourceRerouteNode, meta=(AllowPrivateAccess=true))
    FSourceRerouteNode SourceRerouteNode;
    
public:
    APlacingActuatorConnection();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerPlaceRerouteNode(UPrimitiveComponent* Component, const FVector Location, const FVector Normal);
    
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

