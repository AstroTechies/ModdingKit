// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Control/ControlSymbol.h"
#include "Engine/Texture.h"
#include "Engine/Texture2D.h"
#include "ItemType.generated.h"


USTRUCT(BlueprintType)
struct ASTRO_API FItemRecipeIngredient
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UItemType> ItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float count;
};

USTRUCT(BlueprintType)
struct ASTRO_API FRecipe
{
	GENERATED_USTRUCT_BODY();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FItemRecipeIngredient> Ingredients;
};

UCLASS(BlueprintType, Blueprintable)
class ASTRO_API UItemCatalogCategoryDefinition : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Take a guess
		FText CategoryName;

};

UENUM(BlueprintType)
enum class EItemVariantType : uint8 {
	Pioneer = 0  UMETA(DisplayName = "Left"),
	Engineer = 1 UMETA(DisplayName = "Right"),
};

UCLASS(EditInlineNew)
class ASTRO_API UItemCatalogData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Does this item only show up in the catalog in creative mode?
		bool bIsCreativeModeOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Does this item spawn as a package when spawned in from the catalog in creative mode?
		bool bCreativeSpawnPackaged;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// How many bytes are needed to unlock this entry in the catalog?
		int UnlockCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Is this item the base of its catalog row?
		bool bIsBaseItem = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// If this item is the base of the catalog row, this is the tab of the catalog that the entry is in; otherwise, this is None
		UItemCatalogCategoryDefinition* Category;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Y value (0 = first row of the tab, 1 = second row of the tab, etc.)
		int CategorySequenceNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// A reference to the item that is the base of the catalog row (If this is the base item, leave this as None)
		TSubclassOf<UItemType> BaseItemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Is this entry to the left or the right of the base item in the catalog row? (If this is the base item, leave this as Left)
		EItemVariantType VariantType = EItemVariantType::Pioneer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// |X| (0 = the base entry, 1 = directly before or after the base entry, etc.)
		int VariationSequenceNumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The model that shows in the catalog to represent this item
		UStaticMesh* CatalogMesh;

};

UCLASS(BlueprintType, Blueprintable)
class ASTRO_API UItemType : public UControlSymbol
{
	GENERATED_BODY()
	
public:
	UItemType();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDestroyOnAddDeformation = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Take a guess
		bool Indestructible = false; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Whether the item contributes to an explosion, like Hydrazine
		bool IsVolatile = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Take a guess
		bool IsPower = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Take a guess
		bool IsOxygen = false; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CreativeSpawnEmpty;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UseSquareIconBackground = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Whether or not the item can be put into a shredder
		bool bCanBeScrapped = false; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bApplyTintToHarvestActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Can this item not be packaged with a packager?
		bool bIsUnrepackageable = false; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Not needed
		FLinearColor MaterialColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// The Actor (PhysicalItem) that this ItemType represents
		TSubclassOf<AActor> PickupActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Bundle --> Individual
		TSubclassOf<UItemType> UnbundleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// Individual --> Bundle
		TSubclassOf<UItemType> BundleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRecipe ConstructionRecipe;

	UPROPERTY(EditAnywhere, Instanced, BlueprintReadWrite)
		UItemCatalogData* CatalogData;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UResearchSubjectDefinition* ResearchSubjectDefinition;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture* CrateOverlayTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* WidgetIcon;
};
