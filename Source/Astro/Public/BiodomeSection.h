#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "BiodomeSection.generated.h"

class UBiodomePlantComponent;
class UPrimitiveComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FBiodomeSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> SectionMidpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UPrimitiveComponent> canopyCollision;
    
    UPROPERTY(EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UBiodomePlantComponent>> PlantsInSections;
    
    ASTRO_API FBiodomeSection();
};

