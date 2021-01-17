// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Math/Vector2D.h"
//#include "Engine/EngineTypes.h"
//#include "Components/SceneComponent.h"
//#include "Components/PrimitiveComponent.h"
//#include "GameFramework/Pawn.h"
#include "TooltipComponent.generated.h"



UENUM()
enum class ETooltipProximityState : uint8 {
	WithinPrimaryProximity = 0,
	WithinSecondaryProximity = 1,
	WithinDetailsProximity = 2,
	OutOfRange = 3
};

UENUM()
enum class ETooltipArchetype : uint8 {
	Custom = 0,
	PhysicalItem = 1,
	ItemIndicator = 2,
	ClickableSlot = 3,
	Salvage = 4,
	PlanetProxy = 5,
	CustomNonInputResponding = 6,
	Salvage_Bundleable = 7
};

UENUM()
enum class ETooltipVisibilityControl : uint8 {
	ShowOnFocus = 0,
	BadgeAlwaysDetailsOnFocus = 1,
	BadgeAlwaysDetailsProximity = 2,
	BadgeProximityDetailsOnFocus = 3,
	BadgeAlwaysDetailsCustom = 4,
	BadgeProximityDetailsCustom = 5,
	BadgeProximityDetailsProximity = 6,
	Custom = 7
};

UENUM()
enum class ETooltipState : uint8 {
	Collapsed = 0,
	BadgeVisible = 1,
	FullyPresented = 2
};

UENUM()
enum class ETooltipPresentationStyleTypes : uint8 {
	StandardTooltip = 0,
	BadgelessTooltip = 1,
	AstroInteraction = 2
};


USTRUCT(BlueprintType)
struct ASTRO_API FTooltipProximityBadgeVisibilityData
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BadgeProximityRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DetailsProximityRadius;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SecondaryLongDistanceBadgeProximityRadius;
};


USTRUCT(BlueprintType)
struct ASTRO_API FInteractionPromptEntryData
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ActionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName MappedActionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName AxisName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AxisScale;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsAxisInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText DisplayName;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//EInputKeyInteractionType InteractionType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HoldAnimationProgress;
};

USTRUCT(BlueprintType)
struct ASTRO_API FTooltipWidgetDisplayData
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FInteractionPromptEntryData> InteractionPrompts;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* ResourceObjectBadge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObject* ResourceObjectBadgeBackground;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText SubTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETooltipPresentationStyleTypes PresentationStyle;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//ETooltipAnimationDirection AnimationDirection;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D CustomBadgeSize;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//EAstroGameMenuTutorialSlideDeckKey OpenAstropediaDeck;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//EAstroGameMenuTutoriaSlideCardKey OpenAstropediaCard;





};


UCLASS(BlueprintType, Blueprintable)
class ASTRO_API UTooltipComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTooltipComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D ScreenOffset;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTooltipInteractionActiveDelegate InteractionActivated;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTooltipInputUnhandledDelegate InputUnhandled;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSignal OnOverrideChanged;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsActorDefaultTooltip;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETooltipArchetype TooltipArchetype = ETooltipArchetype::Salvage; // for testing
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETooltipVisibilityControl VisibilityControl;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bRemainsVisibleWhenHeld;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSuppressOtherTooltipsWhenExpanded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bAlwaysShowLiteralItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSuppressTooltipUse;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTooltipProximityBadgeVisibilityData ProximityVisibilityData;
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FComponentReference AttachComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FComponentReference InputRespondingColliderComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* AnchorReferenceComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FTooltipWidgetOverride> WidgetOverrideStack;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTooltipWidgetDisplayData DefaultDisplayData;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanDisplayWhenCracked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroTooltipWidget* TooltipWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* PrimaryProximitySphereBadge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* SecondaryProximitySphereBadge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent* ProximitySphereDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPrimitiveComponent* InputRespondingCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FHoldInputActionProgress ActiveHoldInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TWeakObjectPtr<UInputComponent, FWeakObjectPtr> BoundInputComponent;
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETooltipState DesiredTooltipState;

	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TooltipExpansionSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TooltipCollapseSpeedMultiplier;
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasFocus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsOwnerPickedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsLocalPlayerWithinPrimaryProximitySphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bIsLongDistanceSecondaryBadgeActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bWidgetIsAboutToDie;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bChooseDefaultCollider;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETooltipProximityState TooltipProximityState;
	/*
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ActiveOverrideName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		APawn* LocalPawnDisplayingProximityTooltip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 NumActiveLocalPawnOverlapEvents;*/
	
};