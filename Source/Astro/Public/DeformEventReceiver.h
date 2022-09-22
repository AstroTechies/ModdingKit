#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OnTerrainEventDelegate.h"
#include "OnAcceptResourceDelegate.h"
#include "OnTerrainDeformationDensityDeltaReceivedDelegate.h"
#include "DeformEventReceiver.generated.h"

class AActor;
class UDeformEventReceiver;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeformEventReceiver : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTerrainEvent OnTerrainEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAcceptResource OnAcceptResource;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTerrainDeformationDensityDeltaReceived OnTerrainDeformationDensityDeltaReceived;
    
    UDeformEventReceiver();
    UFUNCTION(BlueprintPure)
    static UDeformEventReceiver* ActorDeformEventReceiver(AActor* Actor);
    
};

