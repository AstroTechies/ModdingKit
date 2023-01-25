#pragma once
#include "CoreMinimal.h"
#include "AstroGameState.h"
#include "GateObjectActivationSignalDelegate.h"
#include "GatesGameStateReplicationData.h"
#include "GatesGameState.generated.h"

UCLASS(Blueprintable)
class ASTRO_API AGatesGameState : public AAstroGameState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGateObjectActivationSignal OnGateObjectActivated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnReplicationDataReceived, meta=(AllowPrivateAccess=true))
    FGatesGameStateReplicationData ReplicationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalActivatedChambers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TotalActivatedEngines;
    
public:
    AGatesGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnReplicationDataReceived();
    
};

