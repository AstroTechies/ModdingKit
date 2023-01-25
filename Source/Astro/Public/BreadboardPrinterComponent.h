#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "BreadboardPrinterAnimationReplicationData.h"
#include "EnableSignalDelegate.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "BreadboardPrinterComponent.generated.h"

class AActor;
class APhysicalItem;
class UAstroSaveCustomArchiveProxy;
class UClickableComponent;
class UPowerComponent;
class UPrimitiveComponent;
class UPrinterComponent;
class USceneComponent;
class USkeletalMeshComponent;
class USphereComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UBreadboardPrinterComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintShaderThickness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanPrintToSelfPlatform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference GroundOutputSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> PrintSpeedsByTier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintSpeedScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintSurfaceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OutOfRangeDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoShutdownEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ActivationRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtensionLerpThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CalculatePrintheadAnimationValues;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtensionLerpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HeightLerpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PrintheadNeutralSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PrintheadDeployedSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PrintheadActualSocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PrintAreaRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* GroundOutputSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* PrinterMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* PrintAreaCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PrintingOntoItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RoomToPrint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintheadHeight_Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrintheadExtension_Current;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_AnimationStateChange, meta=(AllowPrivateAccess=true))
    FBreadboardPrinterAnimationReplicationData REP_AnimationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_OutputSlotTransform, meta=(AllowPrivateAccess=true))
    FTransform REP_OutputSlotTransform;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwnerPhysicalItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrinterComponent* PrinterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UClickableComponent* ClickableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> SelectedBlueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bOverlapListInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FSlotReference SelectedOutputSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float InitialPrintSlotOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_IsInProductionMode, meta=(AllowPrivateAccess=true))
    uint8 bIsProductionModeEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_AutoTerminateProductionMode, meta=(AllowPrivateAccess=true))
    uint8 bAutoTerminateProductionMode: 1;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnAnimationStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnProductionModeChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnAutoTerminateProductionModeChanged;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSet<APhysicalItem*> PlatformsInRange;
    
public:
    UBreadboardPrinterComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void ValidatePackageableItemsInRange();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UpdateBreadboardPrinter(float DeltaTime);
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetRepackageModeEnabled(bool modeEnabled);
    
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_OutputSlotTransform();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_IsInProductionMode();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_AutoTerminateProductionMode();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_AnimationStateChange();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPrintAreaOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPrintAreaOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void HandlePrintStarted();
    
    UFUNCTION(BlueprintCallable)
    void HandlePrintFinished(APhysicalItem* PrintedItem);
    
    UFUNCTION(BlueprintCallable)
    void HandlePrintCanceled();
    
public:
    UFUNCTION(BlueprintCallable)
    FSlotReference GetSlotForItemTier(const TArray<FSlotReference>& Slots, const APhysicalItem* itemCDO, bool neededSlotTierCanBeOccupied) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSelectionEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPrintheadHeight();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPrintheadExtension();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPrinterAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetPreviewEnabled();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure)
    bool CheckPrinterDeployed() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetProductionModeEnabled(bool ProductionModeEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetAutoTerminateProductionModeEnabled(bool AutoTerminateProductionModeEnabled);
    
};

