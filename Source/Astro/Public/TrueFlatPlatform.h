#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeformationParamsT2.h"
#include "TrueFlatPlatform.generated.h"

class UObject;
class UVoxelVolumeComponent;

UCLASS(Blueprintable)
class ASTRO_API ATrueFlatPlatform : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVoxelVolumeComponent* voxelVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> CachedT2Deformables;
    
public:
    ATrueFlatPlatform(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnDeformationComplete(const FDeformationParamsT2& params);
    
};

