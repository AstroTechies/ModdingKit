#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TetherSystemProperties.generated.h"

class UStaticMesh;
class UMaterialInterface;

UCLASS(Blueprintable, Blueprintable)
class UTetherSystemProperties : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    UStaticMesh *SegmentMesh;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *DefaultMaterial;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *IndicatorMaterial;

    UPROPERTY(EditAnywhere)
    UMaterialInterface *NoOxygenMaterial;

    UPROPERTY(EditAnywhere)
    float BreakDistance;

    UPROPERTY(EditAnywhere)
    float SegmentLength;

    UPROPERTY(EditAnywhere)
    float SegmentScale;

    UPROPERTY(EditAnywhere)
    float GravityTension;

    UPROPERTY(EditAnywhere)
    float CurveTension;

    UPROPERTY(EditAnywhere)
    float AdjustDistance;

    UTetherSystemProperties();
};
