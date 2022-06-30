#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameplayTasksComponent.h"
#include "AstroActionRequestPayload.h"
#include "EAstroActionNetworking.h"
#include "AstroActionIdentifier.h"
#include "AstroActionComponent.generated.h"

class UAstroAction;

UCLASS(Blueprintable, EditInlineNew, meta = (BlueprintSpawnableComponent))
class ASTRO_API UAstroActionComponent : public UGameplayTasksComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    TArray<UAstroAction *> ActiveActions;

public:
    UAstroActionComponent(const FObjectInitializer &ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    bool StartActionInstance(UAstroAction *Action, EAstroActionNetworking Networking);

    UFUNCTION(BlueprintCallable)
    bool StartAction(TSubclassOf<UAstroAction> ActionType);

protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestStartAction(const FAstroActionRequestPayload &payload);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerRequestInterruptAction(const FAstroActionIdentifier &actionToInterruptIdentifier);

public:
    UFUNCTION()
    void OnActionEnded(UAstroAction *EndedAction);

protected:
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void MulticastStartAction(const FAstroActionRequestPayload &payload);

    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void MulticastInterruptAction(const FAstroActionIdentifier &interruptedActionIdentifier);

public:
    UFUNCTION(BlueprintCallable)
    UAstroAction *CreateAction(TSubclassOf<UAstroAction> ActionType);

protected:
    UFUNCTION(Client, Reliable, WithValidation)
    void ClientDenyStartActionRequest(const FAstroActionIdentifier &deniedActionIdentifier);
};
