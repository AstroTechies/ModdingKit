#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TetherPostComponent.generated.h"

class UDistanceLightFaderComponent;
class UPowerComponent;
class UTetherAttachComponent;
class UInstancedStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTetherPostComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool Placing;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool Placed;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UTetherAttachComponent *IndicatorAttach;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UPowerComponent *PowerComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UTetherAttachComponent *AttachComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UInstancedStaticMeshComponent *IndicatorInstancedMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UDistanceLightFaderComponent *LightFader;

    UTetherPostComponent();
    UFUNCTION(BlueprintCallable)
    void SetPlacing(bool newPlacing);

private:
    UFUNCTION()
    void OnOwnerPlacedInSlot();

public:
    UFUNCTION(BlueprintCallable)
    void BreakTethers();

    UFUNCTION(BlueprintCallable)
    void AttachTethers(bool fromSave);
};
