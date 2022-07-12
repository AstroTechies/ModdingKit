#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "DeployableItemPackageComponent.generated.h"

class APhysicalItem;
class UMaterialInterface;
class USceneComponent;
class UPrimitiveComponent;
class UItemType;
class UTexture;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeployableItemPackageComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackageReadyEvent, bool, DeployReady);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackageIndicatorEvent, bool, IndicatorVisible);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackagedItemDeployedEvent, APhysicalItem*, DeployedItem);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAssignMaterialEvent, UMaterialInterface*, PackageMaterial);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference PackagePreviewIndicatorSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDeployComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPackagedItemDeployedEvent OnDeployedItemSpawned;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPackageReadyEvent OnDeployReadyChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPackageIndicatorEvent OnIndicatorVisibleChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* PackagePreviewIndicatorSlotWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* PackageVisualsWrapper;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssignMaterialEvent OnAssignPackageMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CurrentIndicatorSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwningItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* UnpackIndicatorRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> UnpackIndicatorRootOriginalMaterials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoNotAutoDestroyOnUnpack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HideIndicatorTimer;
    
public:
    UDeployableItemPackageComponent();
    UFUNCTION(BlueprintCallable)
    void SetupPackagedItem(TSubclassOf<UItemType> ItemTypeToDeploy);
    
private:
    UFUNCTION()
    void SetupHideIndicatorTimer();
    
    UFUNCTION()
    void SetCrateMaterialInstance(UTexture* OverlayTexture);
    
public:
    UFUNCTION(BlueprintCallable)
    UPrimitiveComponent* PreDeployPackagedItem();
    
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
    void GeneralSlotEvent(APhysicalItem* Item);
    
private:
    UFUNCTION()
    void EndCursorOver(AActor* Actor);
    
    UFUNCTION()
    void DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
public:
    UFUNCTION(BlueprintCallable)
    void DeployPackagedItem();
    
private:
    UFUNCTION()
    void ClearHideIndicatorTimer();
    
    UFUNCTION()
    void BeginCursorOver(AActor* Actor);
    
};

