#pragma once
#include "CoreMinimal.h"
#include "CameraModifierComponent.h"
#include "FixedRollModifierComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UFixedRollModifierComponent : public UCameraModifierComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Roll;
    
    UFixedRollModifierComponent(const FObjectInitializer& ObjectInitializer);

};

