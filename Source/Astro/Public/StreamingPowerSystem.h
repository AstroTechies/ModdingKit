#pragma once
#include "CoreMinimal.h"
#include "AstroEntitySystem.h"
#include "StreamingPowerSystem.generated.h"

class AActor;
class UAstroStreamingPowerTickTaskManager;

UCLASS(Blueprintable)
class ASTRO_API UStreamingPowerSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroStreamingPowerTickTaskManager* TaskManager;
    
public:
    UStreamingPowerSystem();
    UFUNCTION(BlueprintCallable)
    static void SplitMergedConnectionBetweenStreamingPowerNodesOnActors(AActor* thisActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    static bool RemovePoweredItemFromActorsPowerNode(AActor* gridNodeOwner, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    static void CreateMergedConnectionBetweenStreamingPowerNodesOnActors(AActor* thisActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    static bool AddPoweredItemToActorsPowerNode(AActor* gridNodeOwner, AActor* OtherActor);
    
};

