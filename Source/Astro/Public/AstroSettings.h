#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/WorldSettings.h"
#include "UObject/NoExportTypes.h"
#include "AstroSettings.generated.h"

class UAstroMissionDataAsset;
class ULevelSequence;
class AAstroSettings;
class AActor;
class AAstroPlanet;
class AGateStation;
class ASolarBody;

UCLASS(Blueprintable, Blueprintable)
class AAstroSettings : public AWorldSettings
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFreePowerChanged, bool, FreePowerEnabled);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bIsFlatland : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bFreePower : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bInteractionLogging : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bSurvival : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bStartAllRecipes : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bLoadAutoSave : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bTrailer : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bRelease : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bBalancePalettes : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bAnalyticsEnabled : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<UAstroMissionDataAsset *> MissionData;

    UPROPERTY(EditDefaultsOnly)
    ULevelSequence *IntroCinematicSequence;

    UPROPERTY(EditDefaultsOnly)
    ULevelSequence *LatestUpdateCinematicSequence;

    UPROPERTY(EditDefaultsOnly)
    ULevelSequence *OutroCinematicSequence;

    UPROPERTY(EditDefaultsOnly)
    FString OutroCinematicAudioEvent;

    UPROPERTY(EditDefaultsOnly)
    FName OutroCinematicMusicState;

    UPROPERTY(EditAnywhere)
    TArray<AActor *> CinematicTerrainResolutionPoints;

    UPROPERTY(EditAnywhere)
    TArray<AActor *> CinematicTerrainResolutionPointsForUpdate;

    UPROPERTY(EditAnywhere)
    TArray<AAstroPlanet *> PlanetsToReseedForCinematic;

    UPROPERTY(EditAnywhere)
    TArray<AAstroPlanet *> PlanetsToReseedForUpdateCinematic;

    UPROPERTY(EditAnywhere)
    uint8 bGateStationPlacedAtRuntime : 1;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AGateStation> GateStationType;

    UPROPERTY(EditAnywhere)
    FVector GateStationSpawnLocation;

    UPROPERTY(EditAnywhere)
    ASolarBody *GateStationOrbitingBody;

    UPROPERTY(EditAnywhere)
    float GateStationOrbitDistance;

    UPROPERTY(EditAnywhere)
    FVector GateStationOrbitDirection;

    UPROPERTY(EditAnywhere)
    FVector GateStationOrbitAxis;

    UPROPERTY(BlueprintAssignable)
    FOnFreePowerChanged OnFreePowerChanged;

    AAstroSettings();
    UFUNCTION(BlueprintPure)
    static AAstroSettings *GetAstroSettings(AActor *Actor);
};
