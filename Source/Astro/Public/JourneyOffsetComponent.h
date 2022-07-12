#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "JourneyOffsetComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UJourneyOffsetComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetAmount;
    
public:
    UJourneyOffsetComponent();
};

