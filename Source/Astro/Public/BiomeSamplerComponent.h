#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnBiomeSampleUpdatedDelegate.h"
#include "BiomeSamplerComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UBiomeSamplerComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickFrequency;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBiomeSampleUpdated OnBiomeSampleUpdated;
    
    UBiomeSamplerComponent(const FObjectInitializer& ObjectInitializer);

};

