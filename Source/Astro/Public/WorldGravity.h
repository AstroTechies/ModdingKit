#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorldGravity.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWorldGravity : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(Export)
    TArray<UPrimitiveComponent *> PrimitiveComponents;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 Enable : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 DisableIfNoTerrain : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAdhocPhysicsGeneration : 1;

    UPROPERTY()
    uint8 bIsSleeping : 1;

    UPROPERTY(SaveGame)
    uint8 TerrainLODAtLastSleep;

public:
    UWorldGravity();
    UFUNCTION()
    void OnComponentSleep(UPrimitiveComponent *SleepingComponent, FName BoneName);

    UFUNCTION()
    void OnComponentAwake(UPrimitiveComponent *WakingComponent, FName BoneName);
};
