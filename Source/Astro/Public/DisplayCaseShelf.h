#pragma once
#include "CoreMinimal.h"
#include "OnCollectionUpdatedDelegate.h"
#include "PhysicalItem.h"
#include "DisplayCaseShelf.generated.h"

class UDynamicWhitelistOrganizationRule;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class ASTRO_API ADisplayCaseShelf : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCollectionUpdated OnCollectionUpdated;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicWhitelistOrganizationRule* SlotOrganizationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStorageChassisComponent* StorageChassis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<APhysicalItem*> CurrentSlottedItems;
    
public:
    ADisplayCaseShelf(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void AuthorityOnSetItem(APhysicalItem* inPhysicalItem);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityOnReleaseItem(APhysicalItem* inPhysicalItem);
    
};

