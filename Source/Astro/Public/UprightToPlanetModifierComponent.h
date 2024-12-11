#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "UprightToPlanetModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UUprightToPlanetModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseTargetLocation: 1;
    
    UUprightToPlanetModifierComponent(const FObjectInitializer& ObjectInitializer);

};

