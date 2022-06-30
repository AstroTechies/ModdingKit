#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "ETeleportationDestinationType.h"
#include "GateObjectReference.h"
#include "ETeleportationBubbleState.h"
#include "UObject/NoExportTypes.h"
#include "TeleportationBubbleReplicationData.h"
#include "TeleportationBubble.generated.h"

class AAstroCharacter;
class UActorAttachmentsComponent;
class UCurveFloat;
class UStaticMeshComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ATeleportationBubble : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnTeleportationStateChanged;

protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UActorAttachmentsComponent *ActorAttachComponent;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *BubbleMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *ProxyBubbleMesh;

    UPROPERTY(EditDefaultsOnly)
    float BubbleExpansionTime;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *BubbleExpansionCurve;

    UPROPERTY(BlueprintReadWrite, SaveGame, Transient, meta = (AllowPrivateAccess = true))
    AAstroCharacter *CharacterBeingTeleported;

    UPROPERTY(SaveGame, Transient)
    ETeleportationDestinationType DestinationType;

    UPROPERTY(SaveGame, Transient)
    FTransform DestinationTransform;

    UPROPERTY(SaveGame, Transient)
    FGateObjectReference DestinationGateObjectRef;

    UPROPERTY(BlueprintReadWrite, SaveGame, Transient, meta = (AllowPrivateAccess = true))
    ETeleportationBubbleState TeleportationState;

    UPROPERTY(SaveGame, Transient)
    float BubbleExpansionTimeRemaining;

    UPROPERTY(SaveGame, Transient)
    FVector PersistentTerrainObservationLocation;

    UPROPERTY(Transient, ReplicatedUsing = OnRep_ReplicationData)
    FTeleportationBubbleReplicationData ReplicationData;

public:
    ATeleportationBubble();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintNativeEvent)
    bool TickPostArrivalEffects();

    UFUNCTION(BlueprintNativeEvent)
    bool TickExpansionEffects();

    UFUNCTION(BlueprintNativeEvent)
    bool TickArrivalExpansionEffects();

    UFUNCTION(BlueprintNativeEvent)
    bool TickAbortionEffects();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TeleportCharacterToPosition(AAstroCharacter *characterToTeleport, const FVector &TargetLocation);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TeleportCharacterToGateObject(AAstroCharacter *characterToTeleport, const FGateObjectReference &GateObjectRef);

protected:
    UFUNCTION()
    void OnRep_ReplicationData();

    UFUNCTION()
    void OnCharacterCompletedBubbleExit(AActor *characterActor);

    UFUNCTION()
    void OnCharacterCompletedBubbleEntry(AActor *characterActor);

    UFUNCTION(BlueprintImplementableEvent)
    void InitializePostArrivalEffects();

    UFUNCTION(BlueprintImplementableEvent)
    void InitializeExpansionEffects();

    UFUNCTION(BlueprintImplementableEvent)
    void InitializeArrivalExpansionEffects();

    UFUNCTION(BlueprintImplementableEvent)
    void InitializeAbortEffects();
};
