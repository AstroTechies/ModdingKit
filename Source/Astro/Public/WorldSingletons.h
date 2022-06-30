#pragma once
#include "CoreMinimal.h"
#include "WorldSingletons.generated.h"

class UAstroEntityWorld;
class ATetherManager;
class UBeaconManager;
class USolarSystem;
class UAutoCraneManager;
class UCollectibleHandler;
class UAstroServerCommWorldDataMap;
class UResourceExtractorManager;
class UCameraFacingManager;
class UCreativeModeData;
class UObject;
class UAstroFoliageDestructionManager;
class USlotOrganizationRuleBroker;
class UVoxelVolumeComponent;

USTRUCT(BlueprintType)
struct FWorldSingletons {
    GENERATED_BODY()
public:
    UPROPERTY()
    UAstroEntityWorld* EntityWorld;
    
    UPROPERTY()
    ATetherManager* TetherManager;
    
    UPROPERTY()
    USolarSystem* SolarSystem;
    
    UPROPERTY()
    UCollectibleHandler* CollectibleHandler;
    
    UPROPERTY(Transient)
    UAstroServerCommWorldDataMap* ServerComm;
    
    UPROPERTY()
    UBeaconManager* BeaconManager;
    
    UPROPERTY()
    UAutoCraneManager* AutoCraneManager;
    
    UPROPERTY()
    UResourceExtractorManager* ResourceExtractorManager;
    
    UPROPERTY()
    UCameraFacingManager* CameraFacingManager;
    
    UPROPERTY()
    UCreativeModeData* CreativeModeData;
    
    UPROPERTY(Transient)
    UObject* PictureRenderTargetLockedObject;
    
    UPROPERTY(Transient)
    UAstroFoliageDestructionManager* FoliageDestructionManager;
    
    UPROPERTY(Transient)
    USlotOrganizationRuleBroker* SlotOrganizationRuleBroker;
    
    UPROPERTY(Export, Transient)
    TArray<UVoxelVolumeComponent*> ActiveVoxelVolumes;
    
    ASTRO_API FWorldSingletons();
};

