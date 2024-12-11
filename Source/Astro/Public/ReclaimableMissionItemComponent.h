#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReclaimableMissionItemComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UReclaimableMissionItemComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString OwnerPlayerID;
    
    UReclaimableMissionItemComponent(const FObjectInitializer& ObjectInitializer);

};

