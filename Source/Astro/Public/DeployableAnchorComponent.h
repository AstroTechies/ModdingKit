#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PreviewData.h"
#include "PreviewDisplayComponent.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "DeployableAnchorComponent.generated.h"

class AActor;
class APhysicalItem;
class UItemType;
class UMaterialInterface;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDeployableAnchorComponent : public UPreviewDisplayComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPackagedItemDeployedEvent, APhysicalItem*, DeployedItem);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMegaStructureSet, float, MegaStructureRadius, FVector, MegaStructureRelativeLocation, float, BuildingPlatformRadius);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPackagedItemDeployedEvent OnDeployedItemSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMegaStructureSet OnMegaStructureSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference platformSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference terrainPreviewSlot_MS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference terrainPreviewSlot_DBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* platformPreviewIndicatorSlotWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* terrainPreviewIndicatorSlotWrapper_MS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* terrainPreviewIndicatorSlotWrapper_DBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCanDeploy: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsPlaced: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bCanShowPreview: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Offset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PackagePreviewIndicatorSlotWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LineTraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyTraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroundTraceDistance;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* BuildingPlatformToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* InvalidPlacementMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> MegaStructureToSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> TerrainPlatformPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreviewData PlatformPreviewData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreviewData MegaStructurePreviewData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreviewData TerrainPreviewData_MS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreviewData TerrainPreviewData_DBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector BuildingPlatformLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MegaStructurePreviewRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BuildingPlatformPreviewRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bRequiresTerrainTrace: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsPlacementValid: 1;
    
public:
    UDeployableAnchorComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UnpackAnchor();
    
    UFUNCTION(BlueprintCallable)
    bool ShowPlatformPreviewWithMaterial(UMaterialInterface* matInstance);
    
private:
    UFUNCTION(BlueprintCallable)
    void ShowAllPreviews(bool bForcePreview);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetupAnchor(const TSubclassOf<UItemType>& PlatformToDeployItemType, const TSubclassOf<UItemType>& MegaStructureToBuildItemType, const TSubclassOf<UItemType>& TerrainPlatformPreviewItemType);
    
    UFUNCTION(BlueprintCallable)
    void SetTerrainPreviewSlotMS(const FSlotReference& NewTerrainPreviewSlot_MS);
    
    UFUNCTION(BlueprintCallable)
    void SetTerrainPreviewSlotDBP(const FSlotReference& NewTerrainPreviewSlot_DBP);
    
    UFUNCTION(BlueprintCallable)
    void SetTerrainPreviewIndicatorSlotWrapperMS(USceneComponent* NewTerrainPreviewIndicatorSlotWrapper_MS);
    
    UFUNCTION(BlueprintCallable)
    void SetTerrainPreviewIndicatorSlotWrapperDBP(USceneComponent* NewTerrainPreviewIndicatorSlotWrapper_DBP);
    
    UFUNCTION(BlueprintCallable)
    void SetStoredItemType(const TSubclassOf<UItemType>& inItemType);
    
    UFUNCTION(BlueprintCallable)
    void SetPlatformSlot(const FSlotReference& NewPlatformSlot);
    
    UFUNCTION(BlueprintCallable)
    void SetPlatformPreviewIndicatorSlotWrapper(USceneComponent* NewPlatformPreviewIndicatorSlotWrapper);
    
    UFUNCTION(BlueprintCallable)
    void SetPackagePreviewIndicatorSlotWrapper(USceneComponent* NewPackagePreviewIndicatorSlotWrapper);
    
    UFUNCTION(BlueprintCallable)
    void SetNeedsTerrainTrace(const bool bInNeedsTerrainTrace);
    
    UFUNCTION(BlueprintCallable)
    void SetMaterialOnAllIndicators(UMaterialInterface* matInstance, bool bForcePreview);
    
    UFUNCTION(BlueprintCallable)
    void SetIsPlaced(const bool inIsPlaced);
    
    UFUNCTION(BlueprintCallable)
    void SetInvalidPlacementMaterial(UMaterialInterface* inMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetCanShowPreview(const bool inCanShowPreview);
    
    UFUNCTION(BlueprintCallable)
    void SetCanDeploy(const bool inCanDeploy);
    
private:
    UFUNCTION(BlueprintCallable)
    void Moved(bool bFromTool);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCurrentPlacementValid() const;
    
private:
    UFUNCTION(BlueprintCallable)
    void EndCursorOver(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
    UFUNCTION(BlueprintCallable)
    void ClearAllIndicators();
    
    UFUNCTION(BlueprintCallable)
    void BeginCursorOver(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void AnchorUnemplacedFromSlot();
    
    UFUNCTION(BlueprintCallable)
    void AnchorReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void AnchorPlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void AnchorEmplacedInSlot();
    
};

