#pragma once
#include "CoreMinimal.h"
#include "TooltipInputUnhandledDelegateDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "TooltipInteractionActiveDelegateDelegate.h"
#include "TooltipWidgetOverride.h"
#include "ETooltipArchetype.h"
#include "ETooltipVisibilityControl.h"
#include "SignalDelegate.h"
#include "TooltipWidgetDisplayData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "TooltipProximityBadgeVisibilityData.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "Components/SphereComponent.h"
#include "ETooltipState.h"
#include "EUseContext.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "ETooltipProximityState.h"
#include "TooltipComponent.generated.h"

class USceneComponent;
class UPrimitiveComponent;
class UAstroTooltipWidget;
class APawn;
class UItemType;
class UObject;
class AActor;
class UCrackableActorComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* AnchorReferenceComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTooltipWidgetOverride> WidgetOverrideStack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTooltipWidgetDisplayData DefaultDisplayData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanDisplayWhenCracked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UAstroTooltipWidget* ToolTipWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USphereComponent* PrimaryProximitySphereBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USphereComponent* SecondaryProximitySphereBadge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USphereComponent* ProximitySphereDetails;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* InputRespondingCollider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* LocalPawnDisplayingProximityTooltip;
    
public:
    UTooltipComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateWidgetOverrideDisplayData(FName overrideName, const FTooltipWidgetDisplayData& DisplayData);
    
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
    void SetupTooltipForItemType(const UItemType* ItemType);
    
protected:
    UFUNCTION()
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
    
    UFUNCTION()
    void SetCustomTooltipReferenceAnchor(USceneComponent* CustomReferenceAnchor);
    
    UFUNCTION(BlueprintCallable)
    void PushTooltipWidgetOverride(FName overrideName, ETooltipVisibilityControl overrideVisibilityControl, bool bInApplyAnchorReferenceOverride, FName AnchorReferenceOverride, bool bInApplyScreenOffsetOverride, FVector2D ScreenOffsetOverride, bool bInRemainsVisibleWhenHeld, bool bInSuppressOtherTooltipsWhenExpanded, bool bInOverrideUseAndExaminePrompts, const FTooltipWidgetDisplayData& DisplayData, const FTooltipProximityBadgeVisibilityData& proximityData);
    
    UFUNCTION(BlueprintCallable)
    void PopTooltipWidgetOverride(FName overrideName);
    
protected:
    UFUNCTION()
    void OnUseContextChanged(EUseContext UseContext);
    
    UFUNCTION()
    void OnTooltipWidgetStateChanged();
    
    UFUNCTION()
    void OnSecondaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnSecondaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void OnProximitySphereEndOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnProximitySphereBeginOverlapDetails(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void OnPrimaryProximitySphereEndOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
    
    UFUNCTION()
    void OnPrimaryProximitySphereBeginOverlapBadge(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION()
    void OnOwningSlotCrackedStateChanged(UCrackableActorComponent* CrackableActorComponent, bool IsCracked);
    
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
    void OnInputUnhandled(TEnumAsByte<EInputEvent> InputType, FName ActionName);
    
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
    AActor* GetActorThisTooltipIsFor();
    
};

