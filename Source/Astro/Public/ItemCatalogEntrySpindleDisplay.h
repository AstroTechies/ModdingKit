#pragma once
#include "CoreMinimal.h"
#include "ItemCatalogEntry.h"
#include "ItemCatalogEntryDisplay.h"
#include "InputCoreTypes.h"
#include "OnItemIconMeshClickedDelegate.h"
#include "ItemCatalogEntrySpindleDisplay.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;
class UMeshComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UItemCatalogEntrySpindleDisplay : public UItemCatalogEntryDisplay
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnItemIconMeshClicked OnItemIconMeshClicked;

protected:
    UPROPERTY(EditDefaultsOnly)
    bool bItemIconMeshesAreClickable;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *UnavailableItemIconMaterial;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *AvailableItemIconMaterial;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *UnlockedItemIconMaterial;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    TArray<UStaticMeshComponent *> ItemIconMeshComponents;

    UPROPERTY(Export, Transient)
    UMeshComponent *ItemIconMeshParent;

    UPROPERTY(Transient)
    TArray<FName> ItemIconMeshSockets;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FItemCatalogEntry CatalogEntry;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    int32 SelectedItemContinuousIndex;

public:
    UItemCatalogEntrySpindleDisplay();
    UFUNCTION(BlueprintCallable)
    void SetItemIconMeshComponents(UMeshComponent *newItemIconMeshParent, const TArray<UStaticMeshComponent *> &newItemIconMeshComponents);

    UFUNCTION()
    void ItemIconMeshClicked(UPrimitiveComponent *clickedComponent, FKey ButtonPressed);

protected:
    UFUNCTION(BlueprintPure)
    int32 ContinuousIndexToItemIconMeshIndex(const int32 continuousIndex) const;
};
