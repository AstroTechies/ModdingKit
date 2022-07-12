#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PhysicalItem.h"
#include "UseToDiscoverItem.generated.h"

class USingleUseConsumableComponent;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API AUseToDiscoverItem : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemTypeDiscoveredOnUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USingleUseConsumableComponent* ConsumableComponent;
    
public:
    AUseToDiscoverItem();
protected:
    UFUNCTION()
    void OnUsed();
    
};

