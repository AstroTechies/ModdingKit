#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReclaimableMissionItemComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UReclaimableMissionItemComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    FString OwnerPlayerID;

    UReclaimableMissionItemComponent();
};
