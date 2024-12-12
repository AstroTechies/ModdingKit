#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MissionKeyItemComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UMissionKeyItemComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName missionId;
    
    UMissionKeyItemComponent(const FObjectInitializer& ObjectInitializer);

};

