#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "DeployableItemPackageComponent.generated.h"

class USceneComponent;
class APhysicalItem;
class UMaterialInterface;
class UPrimitiveComponent;
class UItemType;
class UTexture;
class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDeployableItemPackageComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackageReadyEvent, bool, DeployReady);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackageIndicatorEvent, bool, IndicatorVisible);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackagedItemDeployedEvent, APhysicalItem *, DeployedItem);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAssignMaterialEvent, UMaterialInterface *, PackageMaterial);

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference PackagePreviewIndicatorSlot;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDeployComplete;

    UPROPERTY(BlueprintAssignable)
    FPackagedItemDeployedEvent OnDeployedItemSpawned;

protected:
    UPROPERTY(BlueprintAssignable)
    FPackageReadyEvent OnDeployReadyChanged;

    UPROPERTY(BlueprintAssignable)
    FPackageIndicatorEvent OnIndicatorVisibleChanged;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *PackagePreviewIndicatorSlotWrapper;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *PackageVisualsWrapper;

    UPROPERTY(BlueprintAssignable)
    FAssignMaterialEvent OnAssignPackageMaterial;

private:
    UPROPERTY()
    FSlotReference CurrentIndicatorSlot;

    UPROPERTY()
    APhysicalItem *OwningItem;

    UPROPERTY(Export, Transient)
    UPrimitiveComponent *UnpackIndicatorRoot;

    UPROPERTY(Transient)
    TArray<UMaterialInterface *> UnpackIndicatorRootOriginalMaterials;

    UPROPERTY(EditDefaultsOnly)
    bool DoNotAutoDestroyOnUnpack;

    UPROPERTY()
    FTimerHandle HideIndicatorTimer;

public:
    UDeployableItemPackageComponent();
    UFUNCTION(BlueprintCallable)
    void SetupPackagedItem(TSubclassOf<UItemType> ItemTypeToDeploy);

private:
    UFUNCTION()
    void SetupHideIndicatorTimer();

    UFUNCTION()
    void SetCrateMaterialInstance(UTexture *OverlayTexture);

public:
    UFUNCTION(BlueprintCallable)
    UPrimitiveComponent *PreDeployPackagedItem();

private:
    UFUNCTION()
    void PackageUnemplacedFromSlot();

    UFUNCTION()
    void PackageSetCardinalDirection();

    UFUNCTION()
    void PackageReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void PackagePlacedInSlot();

    UFUNCTION()
    void PackageEmplacedInSlot();

public:
    UFUNCTION()
    void OnItemComponentChanged();

private:
    UFUNCTION()
    void Moved(bool FromTool);

    UFUNCTION()
    void HideIndicator();

public:
    UFUNCTION()
    void GeneralSlotEvent(APhysicalItem *Item);

private:
    UFUNCTION()
    void EndCursorOver(AActor *Actor);

    UFUNCTION()
    void DropInWorld(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

public:
    UFUNCTION(BlueprintCallable)
    void DeployPackagedItem();

private:
    UFUNCTION()
    void ClearHideIndicatorTimer();

    UFUNCTION()
    void BeginCursorOver(AActor *Actor);
};
