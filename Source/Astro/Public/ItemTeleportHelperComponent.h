#pragma once
#include "CoreMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/ActorComponent.h"
#include "ELineOfSightBehavior.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ItemTeleportHelperComponent.generated.h"

class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UItemTeleportHelperComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    float MinLocationDistance;

    UPROPERTY(EditDefaultsOnly)
    float MaxLocationDistance;

    UPROPERTY(EditDefaultsOnly)
    float MaxTeleportHeight;

    UPROPERTY(EditDefaultsOnly)
    float MinTeleportHeight;

    UPROPERTY(EditDefaultsOnly)
    FString RequiredBiome;

    UPROPERTY(EditDefaultsOnly)
    float SightDistance;

    UPROPERTY(EditDefaultsOnly)
    float LOSHeightOffset;

    UPROPERTY(EditDefaultsOnly)
    float AngleStride;

    UPROPERTY(EditDefaultsOnly)
    float MaxStartAngleOffset;

    UPROPERTY(EditDefaultsOnly)
    float TerrainDensityThreshold;

    UPROPERTY(EditDefaultsOnly)
    float MinSurfaceDot;

    UPROPERTY(EditDefaultsOnly)
    int32 MaxFindAttempts;

    UPROPERTY(EditDefaultsOnly)
    TEnumAsByte<EDrawDebugTrace::Type> ShowTrace;

    UItemTeleportHelperComponent();
    UFUNCTION(BlueprintPure)
    bool FindValidSpawnLocationAroundTarget(AActor *Target, const TArray<AActor *> &ActorsToIgnore, ELineOfSightBehavior faceTarget, FVector &outLoc, FRotator &outRot);
};
