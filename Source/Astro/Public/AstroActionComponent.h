#pragma once
#include "CoreMinimal.h"
#include "GameplayTasksComponent.h"
#include "AstroActionIdentifier.h"
#include "AstroActionRequestPayload.h"
#include "EAstroActionNetworking.h"
#include "Templates/SubclassOf.h"
#include "AstroActionComponent.generated.h"

class UAstroAction;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroActionComponent : public UGameplayTasksComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroAction*> ActiveActions;
    
public:
    UAstroActionComponent();
    UFUNCTION(BlueprintCallable)
    bool StartActionInstance(UAstroAction* Action, EAstroActionNetworking Networking);
    
    UFUNCTION(BlueprintCallable)
    bool StartAction(TSubclassOf<UAstroAction> ActionType);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestStartAction(const FAstroActionRequestPayload& payload);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRequestInterruptAction(const FAstroActionIdentifier& actionToInterruptIdentifier);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActionEnded(UAstroAction* EndedAction);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable, WithValidation)
    void MulticastStartAction(const FAstroActionRequestPayload& payload);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable, WithValidation)
    void MulticastInterruptAction(const FAstroActionIdentifier& interruptedActionIdentifier);
    
public:
    UFUNCTION(BlueprintCallable)
    UAstroAction* CreateAction(TSubclassOf<UAstroAction> ActionType);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientDenyStartActionRequest(const FAstroActionIdentifier& deniedActionIdentifier);
    
};

