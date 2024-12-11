#pragma once
#include "CoreMinimal.h"
#include "CustomChildActorComponent.h"
#include "EPhysicalItemTerrainMode.h"
#include "Templates/SubclassOf.h"
#include "ChildPhysicalItemComponent.generated.h"

class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UChildPhysicalItemComponent : public UCustomChildActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APhysicalItem> ChildMovableItemClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhysicalItemTerrainMode TerrainMode;
    
    UChildPhysicalItemComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicalItem* GetChildPhysicalItem();
    
};

