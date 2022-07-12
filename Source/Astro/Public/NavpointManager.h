#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
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
    
    UPROPERTY(EditAnywhere)
    TArray<TWeakObjectPtr<AActor>> SnailNavpointBuffTargets;
    
public:
    UNavpointManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION()
    void OnRep_Navpoints();
    
};

