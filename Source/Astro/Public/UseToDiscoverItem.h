#pragma once
#include "CoreMinimal.h"
#include "PhysicalItem.h"
#include "Templates/SubclassOf.h"
#include "UseToDiscoverItem.generated.h"

class UItemType;
class USingleUseConsumableComponent;

UCLASS(Blueprintable)
class ASTRO_API AUseToDiscoverItem : public APhysicalItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemTypeDiscoveredOnUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USingleUseConsumableComponent* ConsumableComponent;
    
public:
    AUseToDiscoverItem();
protected:
    UFUNCTION(BlueprintCallable)
    void OnUsed();
    
};

