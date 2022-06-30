#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroPackagingAction.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "AstroRepackAction.generated.h"

class UCurveFloat;
class APhysicalItem;
class UItemType;
class ARepackager;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroRepackAction : public UAstroPackagingAction
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    uint8 bMoveRepackingItemAboveTarget : 1;

    UPROPERTY(EditDefaultsOnly)
    float InterpolateToTopOfTargetDuration;

    UPROPERTY(EditDefaultsOnly)
    UCurveFloat *InterpolateToTopOfTargetProgressCurve;

    UPROPERTY(EditDefaultsOnly)
    FName PackageSpawnLocationComponentName;

    UPROPERTY(EditDefaultsOnly)
    FName PackageOffsetComponentName;

    UPROPERTY()
    APhysicalItem *ItemToRepackage;

    UPROPERTY()
    ARepackager *Repackager;

    UPROPERTY()
    TSubclassOf<APhysicalItem> ItemToRepackageType;

    UPROPERTY()
    FGuid ItemToRepackageItemDriveRequestGUID;

    UPROPERTY()
    int32 ReclaimableRewardOwnerPlayerIDHash;

    UPROPERTY(Export)
    UPrimitiveComponent *IndicatorComponent;

    UPROPERTY()
    TSubclassOf<APhysicalItem> PackageTypeToSpawn;

    UPROPERTY()
    TSubclassOf<UItemType> PackagedItemType;

    UPROPERTY()
    FSlotReference SlotToPlacePackageIn;

public:
    UAstroRepackAction();

protected:
    UFUNCTION()
    void OnInterpolationToTopOfTargetFinished();
};
