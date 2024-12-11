#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "CrystalRefineryModuleComponent.generated.h"

class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCrystalRefineryModuleComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> InputSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> OutputSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> InputItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> OutputItemType;
    
    UCrystalRefineryModuleComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateIndicators();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPerformConversion();
    
};

