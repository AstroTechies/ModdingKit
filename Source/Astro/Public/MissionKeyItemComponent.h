#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MissionKeyItemComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UMissionKeyItemComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    FName missionId;

    UMissionKeyItemComponent();
};
