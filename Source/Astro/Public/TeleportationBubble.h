#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "GameFramework/Actor.h"
#include "ETeleportationBubbleState.h"
#include "ETeleportationDestinationType.h"
#include "GateObjectReference.h"
#include "SignalDelegate.h"
#include "TeleportationBubbleReplicationData.h"
#include "TeleportationBubble.generated.h"

class AAstroCharacter;
class UActorAttachmentsComponent;
class UCurveFloat;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API ATeleportationBubble : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTeleportationStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorAttachmentsComponent* ActorAttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* BubbleMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TickPostArrivalEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TickExpansionEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TickArrivalExpansionEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool TickAbortionEffects();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TeleportCharacterToPosition(AAstroCharacter* characterToTeleport, const FVector& TargetLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TeleportCharacterToGateObject(AAstroCharacter* characterToTeleport, const FGateObjectReference& GateObjectRef);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ReplicationData();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterCompletedBubbleExit(AActor* characterActor);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterCompletedBubbleEntry(AActor* characterActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializePostArrivalEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeExpansionEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeArrivalExpansionEffects();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InitializeAbortEffects();
    
};

