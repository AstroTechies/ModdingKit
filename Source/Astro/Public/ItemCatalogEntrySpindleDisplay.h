#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "ItemCatalogEntry.h"
#include "ItemCatalogEntryDisplay.h"
#include "OnItemIconMeshClickedDelegate.h"
#include "ItemCatalogEntrySpindleDisplay.generated.h"

class UMaterialInterface;
class UMeshComponent;
class UPrimitiveComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API UItemCatalogEntrySpindleDisplay : public UItemCatalogEntryDisplay {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnItemIconMeshClicked OnItemIconMeshClicked;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bItemIconMeshesAreClickable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* UnavailableItemIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* AvailableItemIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* UnlockedItemIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> ItemIconMeshComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMeshComponent* ItemIconMeshParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> ItemIconMeshSockets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemCatalogEntry CatalogEntry;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedItemContinuousIndex;
    
public:
    UItemCatalogEntrySpindleDisplay();
    UFUNCTION(BlueprintCallable)
    void SetItemIconMeshComponents(UMeshComponent* newItemIconMeshParent, const TArray<UStaticMeshComponent*>& newItemIconMeshComponents);
    
    UFUNCTION(BlueprintCallable)
    void ItemIconMeshClicked(UPrimitiveComponent* clickedComponent, FKey ButtonPressed);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ContinuousIndexToItemIconMeshIndex(const int32 continuousIndex) const;
    
};

