#pragma once
#include "CoreMinimal.h"
#include "PhysicsComponent.h"
#include "DeformableInterfaceT2.h"
#include "SignalDelegate.h"
#include "DeformationParamsT2.h"
#include "IsBuriedChangedEventDelegate.h"
#include "TerrainPhysicsComponent.generated.h"

class UAstroSaveCustomArchiveProxy;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTerrainPhysicsComponent : public UPhysicsComponent, public IDeformableInterfaceT2
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint8 AutoBlockCamera : 1;

    UPROPERTY(EditAnywhere)
    uint8 CanUnbury : 1;

    UPROPERTY(BlueprintReadWrite, SaveGame, VisibleAnywhere, ReplicatedUsing = OnRep_Buried, meta = (AllowPrivateAccess = true))
    uint8 Buried : 1;

    UPROPERTY()
    FSignal OnSetBuryPhysics;

    UPROPERTY(BlueprintAssignable)
    FSignal OnSetWorldPhysics;

    UPROPERTY(BlueprintAssignable)
    FIsBuriedChangedEvent OnIsBuriedChanged;

    UPROPERTY(EditAnywhere)
    FName OverrideWorldPhysicsProfile;

    UPROPERTY(EditAnywhere)
    FName OverrideBuryPhysicsProfile;

    UTerrainPhysicsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetWorldPhysics();

    UFUNCTION(BlueprintCallable)
    void SetPickupPhysics();

    UFUNCTION(BlueprintCallable)
    void SetIsBuried(bool NewIsBuried);

    UFUNCTION(BlueprintCallable)
    void SetBuryPhysics();

private:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

    UFUNCTION()
    void OnRep_Buried();

public:
    UFUNCTION()
    void OnDeformationComplete(const FDeformationParamsT2 &deformationParams);

    UFUNCTION(BlueprintPure)
    bool IsTerrainBuried();

    UFUNCTION(BlueprintPure)
    bool GetIsBuried() const;

    // Fix for true pure virtual functions not being implemented
};
