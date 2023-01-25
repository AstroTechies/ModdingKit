#pragma once
#include "CoreMinimal.h"
#include "DeformableInterfaceT2.h"
#include "DeformationParamsT2.h"
#include "IsBuriedChangedEventDelegate.h"
#include "PhysicsComponent.h"
#include "SignalDelegate.h"
#include "TerrainPhysicsComponent.generated.h"

class UAstroSaveCustomArchiveProxy;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTerrainPhysicsComponent : public UPhysicsComponent, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 AutoBlockCamera: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CanUnbury: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Buried, meta=(AllowPrivateAccess=true))
    uint8 Buried: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetBuryPhysics;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSetWorldPhysics;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIsBuriedChangedEvent OnIsBuriedChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideWorldPhysicsProfile;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OverrideBuryPhysicsProfile;
    
    UTerrainPhysicsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetWorldPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetPickupPhysics();
    
    UFUNCTION(BlueprintCallable)
    void SetIsBuried(bool NewIsBuried);
    
    UFUNCTION(BlueprintCallable)
    void SetBuryPhysics();
    
private:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Buried(bool previousIsBuried);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDeformationComplete(const FDeformationParamsT2& deformationParams);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTerrainBuried();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsBuried() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

