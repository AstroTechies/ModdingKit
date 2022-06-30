#pragma once
#include "CoreMinimal.h"
#include "AstroStatics.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "EPlanetIdentifier.h"
#include "AtmosphericResource.h"
#include "PlanetStatics.generated.h"

class AActor;
class AAstroPlanet;
class UObject;
class ASolarBody;
class USceneComponent;
class ASun;
class AGateStation;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UPlanetStatics : public UAstroStatics
{
    GENERATED_BODY()
public:
    UPlanetStatics();
    UFUNCTION(BlueprintPure)
    static FVector ToPlanet(AAstroPlanet *Planet, AActor *Actor);

    UFUNCTION(BlueprintCallable)
    static FVector TargetVelocity(FVector Velocity, AActor *Actor, float Time);

    UFUNCTION(BlueprintCallable)
    static void TargetFacingUp(FVector Up, AActor *Actor, float TorqueStrength);

    UFUNCTION(BlueprintCallable)
    static void TargetBody(ASolarBody *Body, AActor *Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);

    UFUNCTION(BlueprintPure)
    static FVector SunDirectionRelativeToSolarBody(UObject *WorldContextObject, const ASolarBody *centerBody, const FVector &WorldPosition);

    UFUNCTION(BlueprintPure)
    static FVector SunDirection(UObject *WorldContextObject, const FVector &WorldPosition);

    UFUNCTION(BlueprintCallable)
    static void SoftLanding(AAstroPlanet *Planet, AActor *Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);

    UFUNCTION(BlueprintPure)
    static FVector PlanetUpComponent(USceneComponent *Component);

    UFUNCTION(BlueprintPure)
    static FVector PlanetUp(const UObject *WorldContextObject, const FVector &WorldPosition);

    UFUNCTION(BlueprintPure)
    static bool PlanetTrace(AActor *Actor, FHitResult &OutHit);

    UFUNCTION(BlueprintPure)
    static bool IsTerrainReadyAtLocation(UObject *WorldContextObject, const FVector &Location);

    UFUNCTION(BlueprintPure)
    static FVector GravityUp(const AActor *Actor);

    UFUNCTION(BlueprintPure)
    static ASun *GetSun(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static ASolarBody *GetSolarBodyByLocation(const UObject *WorldContextObject, FVector Location, bool bDoBoundsCheck, bool bVisitableByPlayerOnly);

    UFUNCTION(BlueprintPure)
    static ASolarBody *GetSolarBody(AActor *Actor, bool bBoundsCheck);

    UFUNCTION(BlueprintPure)
    static TArray<AAstroPlanet *> GetPlanets(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static EPlanetIdentifier GetPlanetIdentifier(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static AAstroPlanet *GetPlanetByLocation(const UObject *WorldContextObject, FVector Position, bool boundsCheck, bool locationIsSolar);

    UFUNCTION(BlueprintPure)
    static AAstroPlanet *GetPlanet(AActor *Actor, bool bBoundsCheck);

    UFUNCTION(BlueprintPure)
    static AGateStation *GetGateStation(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static AAstroPlanet *GetClosestPlanet(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static FVector GetBodyGravityAtLocation(ASolarBody *Body, FVector Location);

    UFUNCTION(BlueprintPure)
    static FVector GetBodyGravity(ASolarBody *Body, AActor *Actor);

    UFUNCTION()
    static void GeneratePlanetGravitySources(UObject *WorldContextObject);

    UFUNCTION(BlueprintPure)
    static FVector FromPlanet(AAstroPlanet *Planet, AActor *Actor);

    UFUNCTION(BlueprintPure)
    static bool EscapedBodyByLocation(ASolarBody *Body, const FVector &Location, float Scale, float Distance, bool locationIsSolar);

    UFUNCTION(BlueprintPure)
    static bool EscapedBody(ASolarBody *Body, AActor *Actor, float Scale, float Distance);

    UFUNCTION(BlueprintPure)
    static bool AreAtmosphericResourcesEqual(const FAtmosphericResource &resourceA, const FAtmosphericResource &resourceB);
};
