#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "CameraFacingWidgetComponent.generated.h"

class USceneComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCameraFacingWidgetComponent : public UWidgetComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WorldPositioningAnchor;
    
public:
    UCameraFacingWidgetComponent(const FObjectInitializer& ObjectInitializer);

};

