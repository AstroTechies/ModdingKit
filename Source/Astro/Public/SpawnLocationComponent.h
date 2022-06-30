#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESpawnPointType.h"
#include "SpawnLocationComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API USpawnLocationComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *Spawn;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IsEnabled;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    ESpawnPointType SpawnType;

    USpawnLocationComponent();
    UFUNCTION(BlueprintCallable)
    void PushSpawnLocation();

    UFUNCTION(BlueprintCallable)
    void PopSpawnLocation();
};
