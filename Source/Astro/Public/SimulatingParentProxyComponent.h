#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SimulatingParentProxyComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API USimulatingParentProxyComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* proxy;
    
    USimulatingParentProxyComponent();
};

