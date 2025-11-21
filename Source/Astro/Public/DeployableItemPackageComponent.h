#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "PreviewData.h"
#include "PreviewDisplayComponent.h"
#include "PreviewDisplayComponent.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "DeployableItemPackageComponent.generated.h"

class AActor;
class APhysicalItem;
class UItemType;
class UPrimitiveComponent;
class USceneComponent;
class UTexture;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeployableItemPackageComponent : public UPreviewDisplayComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackagedItemDeployedEvent, APhysicalItem*, DeployedItem);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDeployComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PackageVisualsWrapper;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPackagedItemDeployedEvent OnDeployedItemSpawned;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PackagePreviewIndicatorSlotWrapper;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoNotAutoDestroyOnUnpack;
    
//    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    UPreviewDisplayComponent::FAssignMaterialEvent OnAssignPackageMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwningItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference CurrentIndicatorSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreviewData PreviewData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle HideIndicatorTimer;
    
public:
    UDeployableItemPackageComponent(const FObjectInitializer& ObjectInitializer);

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

