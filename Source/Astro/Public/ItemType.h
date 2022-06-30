#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ControlSymbol.h"
#include "UObject/NoExportTypes.h"
#include "EItemStorageBehavior.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "Recipe.h"
#include "ItemType.generated.h"

class UTexture;
class UItemType;
class UStaticMesh;
class AActor;
class UItemCatalogData;
class UResearchSubjectDefinition;
class UTexture2D;

UCLASS(Blueprintable, BlueprintType, Blueprintable)
class ASTRO_API UItemType : public UControlSymbol
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bDestroyOnAddDeformation : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 Indestructible : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsVolatile : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsPower : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 IsOxygen : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 CreativeSpawnEmpty : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 UseSquareIconBackground : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bCanBeScrapped : 1;

    UPROPERTY(EditAnywhere)
    uint8 bApplyTintToHarvestActors : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bIsUnrepackageable : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EItemStorageBehavior InternalStorageBehavior;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FName ItemRepackageAudioSwitch;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<TSubclassOf<UItemType>> ContainerSubtypeWhitelist;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor MaterialColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float TerrainCollectionMultiplier;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *TerrainCollectionMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *TerrainVolumeMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> PickupActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> DefaultContainerType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> UnbundleType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> BundleType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> DefaultContainerIndicatorType;

    UPROPERTY(EditDefaultsOnly)
    EAstroGameMenuTutoriaSlideCardKey AstropediaResourceType;

    UPROPERTY(EditDefaultsOnly)
    FString LTEName;

protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRecipe ConstructionRecipe;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bHasAltConstructionRecipe;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FRecipe AltConstructionRecipe;

public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced, meta = (AllowPrivateAccess = true))
    UItemCatalogData *CatalogData;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Instanced, meta = (AllowPrivateAccess = true))
    UResearchSubjectDefinition *ResearchSubjectDefinition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture *CrateOverlayTexture;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D *WidgetIcon;

    UItemType();
    UFUNCTION(BlueprintPure)
    FRecipe GetConstructionRecipe() const;
};
