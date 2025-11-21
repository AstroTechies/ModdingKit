#pragma once
#include "CoreMinimal.h"
#include "AnchorInfo.generated.h"

class AActor;
class USceneComponent;
class USplineComponent;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FAnchorInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USplineComponent> LoadingSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USplineComponent> RestockingSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> MeshWrapper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ButtonActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UStaticMeshComponent> LightIndicator;
    
    ASTRO_API FAnchorInfo();
};

