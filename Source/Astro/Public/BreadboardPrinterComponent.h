#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "EnableSignalDelegate.h"
#include "SlotReference.h"
#include "BreadboardPrinterAnimationReplicationData.h"
#include "UObject/NoExportTypes.h"
#include "SignalDelegate.h"
#include "Engine/EngineTypes.h"
#include "BreadboardPrinterComponent.generated.h"

class USceneComponent;
class APhysicalItem;
class USphereComponent;
class USkeletalMeshComponent;
class UPrinterComponent;
class AActor;
class UPowerComponent;
class UClickableComponent;
class UAstroSaveCustomArchiveProxy;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UBreadboardPrinterComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float PrintShaderThickness;

    UPROPERTY(EditAnywhere)
    bool CanPrintToSelfPlatform;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference GroundOutputSlotRef;

    UPROPERTY(EditAnywhere)
    TArray<float> PrintSpeedsByTier;

    UPROPERTY(EditAnywhere)
    float PrintSpeedScalar;

    UPROPERTY(EditAnywhere)
    float PrintSurfaceRadius;

    UPROPERTY(EditAnywhere)
    float OutOfRangeDuration;

    UPROPERTY(EditAnywhere)
    bool AutoShutdownEnabled;

    UPROPERTY(EditAnywhere)
    float ActivationRange;

    UPROPERTY(EditAnywhere)
    float ExtensionLerpThreshold;

    UPROPERTY(EditAnywhere)
    bool CalculatePrintheadAnimationValues;

    UPROPERTY(EditAnywhere)
    float ExtensionLerpSpeed;

    UPROPERTY(EditAnywhere)
    float HeightLerpSpeed;

    UPROPERTY(EditAnywhere)
    FName PrintheadNeutralSocketName;

    UPROPERTY(EditAnywhere)
    FName PrintheadDeployedSocketName;

    UPROPERTY(EditAnywhere)
    FName PrintheadActualSocketName;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *PrintAreaRoot;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *GroundOutputSlot;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USkeletalMeshComponent *PrinterMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USphereComponent *PrintAreaCollider;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool PrintingOntoItem;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool RoomToPrint;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float PrintheadHeight_Current;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float PrintheadExtension_Current;

    UPROPERTY(BlueprintReadWrite, ReplicatedUsing = OnRep_AnimationStateChange, meta = (AllowPrivateAccess = true))
    FBreadboardPrinterAnimationReplicationData REP_AnimationData;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_OutputSlotTransform)
    FTransform REP_OutputSlotTransform;

protected:
    UPROPERTY(Transient)
    APhysicalItem *OwnerPhysicalItem;

    UPROPERTY(Export, Transient)
    UPrinterComponent *PrinterComponent;

    UPROPERTY(Export, Transient)
    UPowerComponent *PowerComponent;

    UPROPERTY(Export, Transient)
    UClickableComponent *ClickableComponent;

    UPROPERTY(SaveGame)
    TSubclassOf<APhysicalItem> SelectedBlueprint;

    UPROPERTY(SaveGame)
    bool bOverlapListInitialized;

    UPROPERTY(SaveGame)
    FSlotReference SelectedOutputSlot;

    UPROPERTY(SaveGame)
    float InitialPrintSlotOffset;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_IsInProductionMode, meta = (AllowPrivateAccess = true))
    uint8 bIsProductionModeEnabled : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_AutoTerminateProductionMode, meta = (AllowPrivateAccess = true))
    uint8 bAutoTerminateProductionMode : 1;

public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnAnimationStateChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnProductionModeChanged;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnAutoTerminateProductionModeChanged;

private:
    UPROPERTY(SaveGame)
    TSet<APhysicalItem *> PlatformsInRange;

public:
    UBreadboardPrinterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void ValidatePackageableItemsInRange();

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UpdateBreadboardPrinter(float DeltaTime);

protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRepackageModeEnabled(bool modeEnabled);

    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

private:
    UFUNCTION()
    void OnRep_OutputSlotTransform();

    UFUNCTION()
    void OnRep_IsInProductionMode();

    UFUNCTION()
    void OnRep_AutoTerminateProductionMode();

    UFUNCTION()
    void OnRep_AnimationStateChange();

protected:
    UFUNCTION()
    void OnPrintAreaOverlapEnd(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnPrintAreaOverlapBegin(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void HandlePrintStarted();

    UFUNCTION()
    void HandlePrintFinished(APhysicalItem *PrintedItem);

    UFUNCTION()
    void HandlePrintCanceled();

public:
    UFUNCTION()
    FSlotReference GetSlotForItemTier(const TArray<FSlotReference> &Slots, const APhysicalItem *itemCDO, bool neededSlotTierCanBeOccupied) const;

    UFUNCTION(BlueprintPure)
    bool GetSelectionEnabled();

    UFUNCTION(BlueprintPure)
    float GetPrintheadHeight();

    UFUNCTION(BlueprintPure)
    float GetPrintheadExtension();

    UFUNCTION(BlueprintPure)
    bool GetPrinterAvailable();

    UFUNCTION(BlueprintPure)
    bool GetPreviewEnabled();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    bool CheckPrinterDeployed() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetProductionModeEnabled(bool ProductionModeEnabled);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetAutoTerminateProductionModeEnabled(bool AutoTerminateProductionModeEnabled);
};
