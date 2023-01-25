#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TimerHandle -FallbackName=TimerHandle
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "DeployableItemPackageComponent.generated.h"

class AActor;
class APhysicalItem;
class UItemType;
class UMaterialInterface;
class UPrimitiveComponent;
class USceneComponent;
class UTexture;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PackagePreviewIndicatorSlotWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PackageVisualsWrapper;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAssignMaterialEvent OnAssignPackageMaterial;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CurrentIndicatorSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwningItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable)
    void SetupHideIndicatorTimer();
    
    UFUNCTION(BlueprintCallable)
    void SetCrateMaterialInstance(UTexture* OverlayTexture);
    
public:
    UFUNCTION(BlueprintCallable)
    UPrimitiveComponent* PreDeployPackagedItem();
    
private:
    UFUNCTION(BlueprintCallable)
    void PackageUnemplacedFromSlot();
    
    UFUNCTION(BlueprintCallable)
    void PackageSetCardinalDirection();
    
    UFUNCTION(BlueprintCallable)
    void PackageReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void PackagePlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void PackageEmplacedInSlot();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnItemComponentChanged();
    
private:
    UFUNCTION(BlueprintCallable)
    void Moved(bool FromTool);
    
    UFUNCTION(BlueprintCallable)
    void HideIndicator();
    
public:
    UFUNCTION(BlueprintCallable)
    void GeneralSlotEvent(APhysicalItem* Item);
    
private:
    UFUNCTION(BlueprintCallable)
    void EndCursorOver(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
public:
    UFUNCTION(BlueprintCallable)
    void DeployPackagedItem();
    
private:
    UFUNCTION(BlueprintCallable)
    void ClearHideIndicatorTimer();
    
    UFUNCTION(BlueprintCallable)
    void BeginCursorOver(AActor* Actor);
    
};

