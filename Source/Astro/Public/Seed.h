#pragma once
#include "CoreMinimal.h"
#include "OnSpawnedActorDelegate.h"
#include "PhysicalItem.h"
#include "SlotReference.h"
#include "Seed.generated.h"

class ABiodome;
class UPrimitiveComponent;
class UStaticMesh;

UCLASS(Blueprintable)
class ASTRO_API ASeed : public APhysicalItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSpawnedActor OnPlantSpawned;
    
    ASeed(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlantInBiodome(UPrimitiveComponent* canopyCollision, FSlotReference Slot, const bool isGrowBonusActive, const ABiodome* Biodome);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    UStaticMesh* GetSeedMesh();
    
    UFUNCTION(BlueprintCallable)
    void AddAdaptiveTickComponent();
    
};

