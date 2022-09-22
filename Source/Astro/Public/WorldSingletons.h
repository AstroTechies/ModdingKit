#pragma once
#include "CoreMinimal.h"
#include "WorldSingletons.generated.h"

class UAstroEntityWorld;
class UAutoCraneManager;
class UCollectibleHandler;
class UObject;
class ATetherManager;
class USlotOrganizationRuleBroker;
class UCameraFacingManager;
class UResourceExtractorManager;
class UBeaconManager;
class USolarSystem;
class UAstroServerCommWorldDataMap;
class UCreativeModeData;
class UAstroFoliageDestructionManager;
class UVoxelVolumeComponent;

USTRUCT(BlueprintType)
struct FWorldSingletons {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroEntityWorld* EntityWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ATetherManager* TetherManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USolarSystem* SolarSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCollectibleHandler* CollectibleHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroServerCommWorldDataMap* ServerComm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconManager* BeaconManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAutoCraneManager* AutoCraneManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceExtractorManager* ResourceExtractorManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCameraFacingManager* CameraFacingManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreativeModeData* CreativeModeData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* PictureRenderTargetLockedObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroFoliageDestructionManager* FoliageDestructionManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USlotOrganizationRuleBroker* SlotOrganizationRuleBroker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UVoxelVolumeComponent*> ActiveVoxelVolumes;
    
    ASTRO_API FWorldSingletons();
};

