#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AstroPackagingAction.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "AstroRepackAction.generated.h"

class APhysicalItem;
class ARepackager;
class UCurveFloat;
class UItemType;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroRepackAction : public UAstroPackagingAction {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bMoveRepackingItemAboveTarget: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpolateToTopOfTargetDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* InterpolateToTopOfTargetProgressCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PackageSpawnLocationComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PackageOffsetComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemToRepackage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARepackager* Repackager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> ItemToRepackageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid ItemToRepackageItemDriveRequestGUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReclaimableRewardOwnerPlayerIDHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* IndicatorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> PackageTypeToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> PackagedItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference SlotToPlacePackageIn;
    
public:
    UAstroRepackAction();

protected:
    UFUNCTION(BlueprintCallable)
    void OnInterpolationToTopOfTargetFinished();
    
};

