#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EMegastructureType.h"
#include "EPlanetIdentifier.h"
#include "MuseumState.h"
#include "StructureSpawnedNumChangeDelegate.h"
#include "MegastructureManager.generated.h"

class AMegaStructure;
class APhysicalItem;

UCLASS(Blueprintable)
class ASTRO_API UMegastructureManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStructureSpawnedNumChange OnMegastructureNumChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStructureSpawnedNumChange OnBuildingPlatformNumChange;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FMuseumState MuseumState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasCachedMuseumState: 1;
    
public:
    UMegastructureManager();

    UFUNCTION(BlueprintCallable)
    bool RemoveMegastructure(AMegaStructure* inMegastructure);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveBuildingPlatform(APhysicalItem* inBuildingPlatform, const EMegastructureType inMegastructureType);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveAnchor(APhysicalItem* inAnchor, const EMegastructureType inAnchorType);
    
    UFUNCTION(BlueprintCallable)
    void RegisterBuildingPlatform(APhysicalItem* inBuildingPlatform, const EMegastructureType inMegastructureType);
    
    UFUNCTION(BlueprintCallable)
    void RegisterAnchor(APhysicalItem* inAnchor, const EMegastructureType inAnchorType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMegastructureOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMegastructureOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBuildingPlatformOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBuildingPlatformOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnchorOfTypeOnPlanet(const EMegastructureType inAnchorType, const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnchorOfTypeInSolarSystem(const EMegastructureType inAnchorType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMegaStructure* GetUniqueMegastructureOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicalItem* GetUniqueAnchorOfTypeInSolarSystem(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMegastructuresCountOfType(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMegaStructure* GetMegastructureOfTypeOnPlanet(const EMegastructureType inMegastructureType, const EPlanetIdentifier inPlanetId) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetMaxAllowedMegastructuresOfType(const EMegastructureType inMegastructureType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetBuildingPlatformsCountOfType(const EMegastructureType inMegastructureType) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicalItem* GetAnchorOfTypeOnPlanet(const EMegastructureType inAnchorType, const EPlanetIdentifier inPlanetId) const;
    
};

