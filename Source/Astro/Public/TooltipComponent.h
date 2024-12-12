#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "ETooltipArchetype.h"
#include "ETooltipProximityState.h"
#include "ETooltipState.h"
#include "ETooltipVisibilityControl.h"
#include "EUseContext.h"
#include "SignalDelegate.h"
#include "TooltipInputUnhandledDelegateDelegate.h"
#include "TooltipInteractionActiveDelegateDelegate.h"
#include "TooltipProximityBadgeVisibilityData.h"
#include "TooltipWidgetDisplayData.h"
#include "TooltipWidgetOverride.h"
#include "TooltipComponent.generated.h"

class AActor;
class APawn;
class UAstroTooltipWidget;
class UCrackableActorComponent;
class UItemType;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class USphereComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTooltipComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipInteractionActiveDelegate InteractionActivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipInputUnhandledDelegate InputUnhandled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnOverrideChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScreenOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bIsActorDefaultTooltip: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipArchetype TooltipArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETooltipVisibilityControl VisibilityControl;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bRemainsVisibleWhenHeld: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSuppressOtherTooltipsWhenExpanded: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAlwaysShowLiteralItemType: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSuppressTooltipUse: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipProximityBadgeVisibilityData ProximityVisibilityData;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference AttachComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference InputRespondingColliderComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* AnchorReferenceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTooltipWidgetOverride> WidgetOverrideStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData DefaultDisplayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanDisplayWhenCracked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAstroTooltipWidget* ToolTipWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* PrimaryProximitySphereBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SecondaryProximitySphereBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ProximitySphereDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* InputRespondingCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* LocalPawnDisplayingProximityTooltip;
    
public:
    UTooltipComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateWidgetOverrideDisplayData(FName overrideName, const FTooltipWidgetDisplayData& DisplayData);
    
    UFUNCTION(BlueprintCallable)
    void UpdateWidgetOverrideDescriptionText(FName overrideName, FText newDescription);
    
    UFUNCTION(BlueprintCallable)
    void UpdateCorrectedPivotLocation();
    
    UFUNCTION(BlueprintCallable)
    void UpdateActiveHoldInput();
    
    UFUNCTION(BlueprintCallable)
    void StopCurrentHoldAction(bool InputActionSucceeded);
    
    UFUNCTION(BlueprintCallable)
    void SetupTooltipReferenceAnchor();
    
    UFUNCTION(BlueprintCallable)
    void SetupTooltipForItemType(const UItemType* ItemType);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetupTooltipForCurrentDisplaySettings();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetTooltipTitle(FText NewTitle);
    
    UFUNCTION(BlueprintCallable)
    void SetTooltipBadgeImage(UObject* ResourceObjectBadge);
    
    UFUNCTION(BlueprintCallable)
    void SetTooltipBadgeColor(FLinearColor NewBadgeColor);
    
    UFUNCTION(BlueprintCallable)
    void SetInputRespondingCollider(UPrimitiveComponent* NewInputRespondingCollider);
    
    UFUNCTION(BlueprintCallable)
    void SetHasFocus(bool bInHasFocus);
    
    UFUNCTION(BlueprintCallable)
    void SetDesiredTooltipState(ETooltipState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetCustomTooltipReferenceAnchor(USceneComponent* CustomReferenceAnchor);
    
    UFUNCTION(BlueprintCallable)
    void PushTooltipWidgetOverride(FName overrideName, ETooltipVisibilityControl overrideVisibilityControl, bool bInApplyAnchorReferenceOverride, FName AnchorReferenceOverride, bool bInApplyScreenOffsetOverride, FVector2D ScreenOffsetOverride, bool bInRemainsVisibleWhenHeld, bool bInSuppressOtherTooltipsWhenExpanded, bool bInOverrideUseAndExaminePrompts, const FTooltipWidgetDisplayData& DisplayData, const FTooltipProximityBadgeVisibilityData& proximityData);
    
    UFUNCTION(BlueprintCallable)
    void PopTooltipWidgetOverride(FName overrideName);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnUseContextChanged(EUseContext UseContext);
    
    UFUNCTION(BlueprintCallable)
    void OnTooltipWidgetStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnSecondaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnSecondaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnProximitySphereEndOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnProximitySphereBeginOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnPrimaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnOwningSlotCrackedStateChanged(UCrackableActorComponent* CrackableActorComponent, bool IsCracked);
    
    UFUNCTION(BlueprintCallable)
    void OnOwningItemReleasedFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void OnOwningItemPlacedInSlot();
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerUseAvailabilityChanged(bool bIsUsable);
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerItemTypeChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnInteractionActivated(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    void OnInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnActionInputReleased(FName ActionName);
    
    UFUNCTION(BlueprintCallable)
    void OnActionInputPressed(FName ActionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTooltipOverride(FName overrideName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETooltipVisibilityControl GetVisibilityControl() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETooltipProximityState GetProximityState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetHasFocus() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETooltipState GetDesiredState() const;
    
    UFUNCTION(BlueprintCallable)
    AActor* GetActorThisTooltipIsFor();
    
protected:
    UFUNCTION(BlueprintCallable)
    void FullyPresentTooltip();
    
};

