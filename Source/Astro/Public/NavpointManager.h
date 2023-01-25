#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navpoint.h"
#include "NavpointManager.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UNavpointManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Navpoints, meta=(AllowPrivateAccess=true))
    TArray<FNavpoint> Navpoints;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> SnailNavpointBuffTargets;
    
public:
    UNavpointManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_Navpoints();
    
};

