#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AstroStatics.h"
#include "AtmosphericResource.h"
#include "EPlanetIdentifier.h"
#include "PlanetStatics.generated.h"

class AActor;
class AAstroPlanet;
class AGateStation;
class ASolarBody;
class ASun;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API UPlanetStatics : public UAstroStatics {
    GENERATED_BODY()
public:
    UPlanetStatics();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector ToPlanet(AAstroPlanet* Planet, AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static FVector TargetVelocity(FVector Velocity, AActor* Actor, float Time);
    
    UFUNCTION(BlueprintCallable)
    static void TargetFacingUp(FVector Up, AActor* Actor, float TorqueStrength);
    
    UFUNCTION(BlueprintCallable)
    static void TargetBody(ASolarBody* Body, AActor* Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector SunDirectionRelativeToSolarBody(UObject* WorldContextObject, const ASolarBody* centerBody, const FVector& WorldPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector SunDirection(UObject* WorldContextObject, const FVector& WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    static void SoftLanding(AAstroPlanet* Planet, AActor* Actor, float AccelTime, float TimeToSurface, float MinVelocity, float MaxVelocity, float RotationTorque, float DistanceBuffer);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector PlanetUpComponent(USceneComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static FVector PlanetUp(const UObject* WorldContextObject, const FVector& WorldPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool PlanetTrace(AActor* Actor, FHitResult& OutHit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsTerrainReadyAtLocation(UObject* WorldContextObject, const FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GravityUp(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ASun* GetSun(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static ASolarBody* GetSolarBodyByLocation(const UObject* WorldContextObject, FVector Location, bool bDoBoundsCheck, bool bVisitableByPlayerOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ASolarBody* GetSolarBody(AActor* Actor, bool bBoundsCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TArray<AAstroPlanet*> GetPlanets(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EPlanetIdentifier GetPlanetIdentifier(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroPlanet* GetPlanetByLocation(const UObject* WorldContextObject, FVector Position, bool boundsCheck, bool locationIsSolar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroPlanet* GetPlanetByID(UObject* WorldContextObject, EPlanetIdentifier ID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AAstroPlanet* GetPlanet(AActor* Actor, bool bBoundsCheck);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AGateStation* GetGateStation(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AAstroPlanet* GetClosestPlanet(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetBodyGravityAtLocation(ASolarBody* Body, FVector Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetBodyGravity(ASolarBody* Body, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void GeneratePlanetGravitySources(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector FromPlanet(AAstroPlanet* Planet, AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EscapedBodyByLocation(ASolarBody* Body, const FVector& Location, float Scale, float Distance, bool locationIsSolar);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool EscapedBody(ASolarBody* Body, AActor* Actor, float Scale, float Distance);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreAtmosphericResourcesEqual(const FAtmosphericResource& resourceA, const FAtmosphericResource& resourceB);
    
};

