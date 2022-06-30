#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "VintageProbeUnlockBehaviorDefinition.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UVintageProbeUnlockBehaviorDefinition : public UAstroEntityComponentSubobjectDefinition
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> RealityTearObject;

    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> RealityTearFlickerObject;

    UPROPERTY(EditDefaultsOnly)
    FComponentReference RealityTearSpawnLocation;

    UPROPERTY(EditDefaultsOnly)
    FAstroNotificationUnlockAuthoringData ActivatingPlayerUnlockNotification;

    UPROPERTY(EditDefaultsOnly)
    FAstroNotificationUnlockAuthoringData OtherPlayersUnlockNotification;

    UPROPERTY(EditDefaultsOnly)
    TArray<FString> UnlockItems;

    UVintageProbeUnlockBehaviorDefinition();
};
