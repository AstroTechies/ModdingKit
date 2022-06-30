#pragma once
#include "CoreMinimal.h"
#include "ETooltipVisibilityControl.h"
#include "Components/ActorComponent.h"
#include "TooltipWidgetDisplayData.h"
#include "SignalDelegate.h"
#include "TooltipInteractionActiveDelegateDelegate.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "TooltipInputUnhandledDelegateDelegate.h"
#include "ETooltipArchetype.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "TooltipWidgetOverride.h"
#include "UObject/NoExportTypes.h"
#include "ETooltipState.h"
#include "EUseContext.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "ETooltipProximityState.h"
#include "TooltipComponent.generated.h"

class USceneComponent;
class UAstroTooltipWidget;
class USphereComponent;
class UPrimitiveComponent;
class APawn;
class UItemType;
class UObject;
class AActor;
class UCrackableActorComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTooltipComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FTooltipInteractionActiveDelegate InteractionActivated;

    UPROPERTY()
    FTooltipInputUnhandledDelegate InputUnhandled;

    UPROPERTY()
    FSignal OnOverrideChanged;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FVector2D ScreenOffset;

    UPROPERTY(EditDefaultsOnly)
    uint8 bIsActorDefaultTooltip : 1;

protected:
    UPROPERTY(EditAnywhere)
    ETooltipArchetype TooltipArchetype;

    UPROPERTY(EditAnywhere)
    ETooltipVisibilityControl VisibilityControl;

    UPROPERTY(EditAnywhere)
    uint8 bRemainsVisibleWhenHeld : 1;

    UPROPERTY(EditAnywhere)
    uint8 bSuppressOtherTooltipsWhenExpanded : 1;

    UPROPERTY(EditAnywhere)
    uint8 bAlwaysShowLiteralItemType : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bSuppressTooltipUse : 1;

    UPROPERTY(EditAnywhere)
    FTooltipProximityBadgeVisibilityData ProximityVisibilityData;

    UPROPERTY(EditAnywhere)
    FComponentReference AttachComponent;

    UPROPERTY(EditAnywhere)
    FComponentReference InputRespondingColliderComponent;

    UPROPERTY(Export)
    USceneComponent *AnchorReferenceComponent;

    UPROPERTY(EditAnywhere)
    TArray<FTooltipWidgetOverride> WidgetOverrideStack;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FTooltipWidgetDisplayData DefaultDisplayData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bCanDisplayWhenCracked;

    UPROPERTY(Export, Transient)
    UAstroTooltipWidget *ToolTipWidget;

    UPROPERTY(Export)
    USphereComponent *PrimaryProximitySphereBadge;

    UPROPERTY(Export)
    USphereComponent *SecondaryProximitySphereBadge;

    UPROPERTY(Export)
    USphereComponent *ProximitySphereDetails;

    UPROPERTY(Export)
    UPrimitiveComponent *InputRespondingCollider;

    UPROPERTY(Transient)
    APawn *LocalPawnDisplayingProximityTooltip;

public:
    UTooltipComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateWidgetOverrideDisplayData(FName overrideName, const FTooltipWidgetDisplayData &DisplayData);

    UFUNCTION(BlueprintCallable)
    void UpdateWidgetOverrideDescriptionText(FName overrideName, FText newDescription);

    UFUNCTION()
    void UpdateCorrectedPivotLocation();

    UFUNCTION()
    void UpdateActiveHoldInput();

    UFUNCTION()
    void StopCurrentHoldAction(bool InputActionSucceeded);

    UFUNCTION()
    void SetupTooltipReferenceAnchor();

    UFUNCTION(BlueprintCallable)
    void SetupTooltipForItemType(const UItemType *ItemType);

protected:
    UFUNCTION()
    void SetupTooltipForCurrentDisplaySettings();

public:
    UFUNCTION(BlueprintCallable)
    void SetTooltipTitle(FText NewTitle);

    UFUNCTION(BlueprintCallable)
    void SetTooltipBadgeImage(UObject *ResourceObjectBadge);

    UFUNCTION(BlueprintCallable)
    void SetTooltipBadgeColor(FLinearColor NewBadgeColor);

    UFUNCTION(BlueprintCallable)
    void SetInputRespondingCollider(UPrimitiveComponent *NewInputRespondingCollider);

    UFUNCTION(BlueprintCallable)
    void SetHasFocus(bool bInHasFocus);

    UFUNCTION(BlueprintCallable)
    void SetDesiredTooltipState(ETooltipState NewState);

    UFUNCTION()
    void SetCustomTooltipReferenceAnchor(USceneComponent *CustomReferenceAnchor);

    UFUNCTION(BlueprintCallable)
    void PushTooltipWidgetOverride(FName overrideName, ETooltipVisibilityControl overrideVisibilityControl, bool bInApplyAnchorReferenceOverride, FName AnchorReferenceOverride, bool bInApplyScreenOffsetOverride, FVector2D ScreenOffsetOverride, bool bInRemainsVisibleWhenHeld, bool bInSuppressOtherTooltipsWhenExpanded, bool bInOverrideUseAndExaminePrompts, const FTooltipWidgetDisplayData &DisplayData, const FTooltipProximityBadgeVisibilityData &proximityData);

    UFUNCTION(BlueprintCallable)
    void PopTooltipWidgetOverride(FName overrideName);

protected:
    UFUNCTION()
    void OnUseContextChanged(EUseContext UseContext);

    UFUNCTION()
    void OnTooltipWidgetStateChanged();

    UFUNCTION()
    void OnSecondaryProximitySphereEndOverlapBadge(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex);

    UFUNCTION()
    void OnSecondaryProximitySphereBeginOverlapBadge(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnProximitySphereEndOverlapDetails(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex);

    UFUNCTION()
    void OnProximitySphereBeginOverlapDetails(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnPrimaryProximitySphereEndOverlapBadge(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex);

    UFUNCTION()
    void OnPrimaryProximitySphereBeginOverlapBadge(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnOwningSlotCrackedStateChanged(UCrackableActorComponent *CrackableActorComponent, bool IsCracked);

    UFUNCTION()
    void OnOwningItemReleasedFromSlot(bool NewOwner);

    UFUNCTION()
    void OnOwningItemPlacedInSlot();

    UFUNCTION()
    void OnOwnerUseAvailabilityChanged(bool bIsUsable);

    UFUNCTION()
    void OnOwnerItemTypeChanged();

    UFUNCTION()
    void OnInteractionActivated(FName ActionName);

    UFUNCTION()
    void OnInputUnhandled(EInputEvent InputType, FName ActionName);

public:
    UFUNCTION()
    void OnActionInputReleased(FName ActionName);

    UFUNCTION()
    void OnActionInputPressed(FName ActionName);

    UFUNCTION(BlueprintPure)
    bool HasTooltipOverride(FName overrideName);

    UFUNCTION(BlueprintPure)
    ETooltipVisibilityControl GetVisibilityControl() const;

    UFUNCTION(BlueprintPure)
    ETooltipProximityState GetProximityState() const;

    UFUNCTION(BlueprintPure)
    bool GetHasFocus() const;

    UFUNCTION(BlueprintPure)
    ETooltipState GetDesiredState() const;

    UFUNCTION()
    AActor *GetActorThisTooltipIsFor();
};
