#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnTerrainEventDelegate.h"
#include "OnAcceptResourceDelegate.h"
#include "OnTerrainDeformationDensityDeltaReceivedDelegate.h"
#include "DeformEventReceiver.generated.h"

class AActor;
class UDeformEventReceiver;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDeformEventReceiver : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnTerrainEvent OnTerrainEvent;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnAcceptResource OnAcceptResource;

    UPROPERTY(BlueprintAssignable)
    FOnTerrainDeformationDensityDeltaReceived OnTerrainDeformationDensityDeltaReceived;

    UDeformEventReceiver();
    UFUNCTION(BlueprintPure)
    static UDeformEventReceiver *ActorDeformEventReceiver(AActor *Actor);
};
