#pragma once
#include "CoreMinimal.h"
#include "WorldSingletons.generated.h"

class ATetherManager;
class UAstroEntityWorld;
class UAstroFoliageDestructionManager;
class UAstroServerCommWorldDataMap;
class UAutoCraneManager;
class UBeaconManager;
class UCameraFacingManager;
class UCollectibleHandler;
class UCreativeModeData;
class UObject;
class UResourceExtractorManager;
class USlotOrganizationRuleBroker;
class USolarSystem;
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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UVoxelVolumeComponent*> ActiveVoxelVolumes;
    
    ASTRO_API FWorldSingletons();
};

