#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/SceneComponent.h"
#include "UObject/NoExportTypes.h"
#include "DeformableInterfaceT2.h"
#include "SignalDelegate.h"
#include "DeformationParamsT2.h"
#include "ItemPad.generated.h"

class AItemPadActor;
class UAstroSaveCustomArchiveProxy;
class UPrimitiveComponent;
class AActor;
class UItemPad;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UItemPad : public USceneComponent, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    bool AutoSpawn;

    UPROPERTY(EditAnywhere)
    bool ManuallyReplicatePadTransform;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AItemPadActor> PadClass;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSpawnPad;

    UPROPERTY(BlueprintAssignable)
    FSignal OnDestroyPad;

    UPROPERTY(BlueprintReadWrite, SaveGame, ReplicatedUsing = OnRep_Pad, meta = (AllowPrivateAccess = true))
    AItemPadActor *Pad;

    UItemPad();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

private:
    UFUNCTION()
    void StartInWorld();

public:
    UFUNCTION(BlueprintCallable)
    void SpawnPad(bool withTool, UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

private:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

    UFUNCTION()
    void ReleaseFromSlot(bool NewOwner);

    UFUNCTION()
    void PlaceInSlot();

    UFUNCTION()
    void PickUpFromWorld(bool PhysicalMovement);

    UFUNCTION()
    void OnRep_Pad();

public:
    UFUNCTION()
    void OnDeformationComplete(const FDeformationParamsT2 &deformationParams);

private:
    UFUNCTION()
    void MotionStateChanged();

    UFUNCTION()
    void EmplaceInSlot();

    UFUNCTION()
    void DropInWorld(UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

public:
    UFUNCTION(BlueprintPure)
    static UItemPad *ActorItemPad(AActor *Actor);

    // Fix for true pure virtual functions not being implemented
};
