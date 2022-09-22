#pragma once
#include "CoreMinimal.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "ETeleportationDestinationType.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "GateObjectReference.h"
#include "ETeleportationBubbleState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "TeleportationBubbleReplicationData.h"
#include "TeleportationBubble.generated.h"

class UActorAttachmentsComponent;
class UCurveFloat;
class AAstroCharacter;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ATeleportationBubble : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTeleportationStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UActorAttachmentsComponent* ActorAttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BubbleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* ProxyBubbleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BubbleExpansionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* BubbleExpansionCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* CharacterBeingTeleported;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    ETeleportationDestinationType DestinationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FTransform DestinationTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FGateObjectReference DestinationGateObjectRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    ETeleportationBubbleState TeleportationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    float BubbleExpansionTimeRemaining;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    FVector PersistentTerrainObservationLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ReplicationData, meta=(AllowPrivateAccess=true))
    FTeleportationBubbleReplicationData ReplicationData;
    
public:
    ATeleportationBubble();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
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
    void TeleportCharacterToPosition(AAstroCharacter* characterToTeleport, const FVector& TargetLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TeleportCharacterToGateObject(AAstroCharacter* characterToTeleport, const FGateObjectReference& GateObjectRef);
    
protected:
    UFUNCTION()
    void OnRep_ReplicationData();
    
    UFUNCTION()
    void OnCharacterCompletedBubbleExit(AActor* characterActor);
    
    UFUNCTION()
    void OnCharacterCompletedBubbleEntry(AActor* characterActor);
    
    UFUNCTION(BlueprintImplementableEvent)
    void InitializePostArrivalEffects();
    
    UFUNCTION(BlueprintImplementableEvent)
    void InitializeExpansionEffects();
    
    UFUNCTION(BlueprintImplementableEvent)
    void InitializeArrivalExpansionEffects();
    
    UFUNCTION(BlueprintImplementableEvent)
    void InitializeAbortEffects();
    
};

