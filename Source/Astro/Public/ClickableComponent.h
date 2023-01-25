#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
#include "Components/ActorComponent.h"
#include "ClickableDelegateNewDelegate.h"
#include "EUseContext.h"
#include "EUseType.h"
#include "InteractionRedirect.h"
#include "UseContextChangeDelegateDelegate.h"
#include "UseStateChangeDelegateDelegate.h"
#include "UseSuppressionState.h"
#include "ClickableComponent.generated.h"

class AActor;
class APlayerController;
class UClickableComponent;
class USceneComponent;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UClickableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PositioningComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PrimaryIndicatorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* SecondaryIndicatorMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrimaryIndicatorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PrimaryHoverHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondaryIndicatorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 BackpackInteraction: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ShowPrimaryIndicator: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ShowPrimaryIcon: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CaptureDeformTool: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 EncapsulateChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 DisablePrimitiveClicks: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ReplaceChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AllowNonOwnerClicks: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 LocalPrimitiveClicksOnly: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CaptureViewActor: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 UnencapsulateChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Unclickable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 NoGamepadAutoselect: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Unmovable: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSlowVirtualCursorOnHover: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bExcludeNonInteractPrimitivesFromGamepadAutoFocus: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HasUseInteractionByDefault: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HasAuxSlotUseByDefault: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HasActuatorUseByDefault: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HasUseWhilePlayerDriving: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 HasInfoOnlyTooltipWhilePlayerDriving: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 UseActionRequriesHold: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseOverridePivotOffset: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SecondaryInteractionTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D InteractionWidgetPivot;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickableDelegateNew OnQueryClickable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseStateChangeDelegate OnUseStateChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUseContextChangeDelegate OnUseContextChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUseContext DefaultUseContext;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_UseSuppressionState, meta=(AllowPrivateAccess=true))
    FUseSuppressionState UseSuppressionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionRedirect InteractionRedirect;
    
public:
    UClickableComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetInteractionRedirectActor(AActor* Actor, USceneComponent* PivotComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveUseContext(EUseContext NewUseContext);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushUseSuppression_AuthorityOnly(const FName SuppressionId, EUseType useTypeFlags);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PushOrPopUseSuppression_AuthorityOnly(FName SuppressionId, bool shouldSuppress, EUseType useTypeFlags);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PopUseSuppression_AuthorityOnly(const FName SuppressionId);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_UseSuppressionState();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInteractionRedirect();
    
    UFUNCTION(BlueprintCallable)
    bool GetUseCapability(EUseType useType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetUseAvailability(const APlayerController* Instigator, EUseType useType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USceneComponent* GetPositionComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static USceneComponent* GetActorClickableOrRoot(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UClickableComponent* GetActorClickableOrDefault(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EUseContext GetActiveUseContext() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UClickableComponent* ActorClickable(AActor* Actor);
    
};

