#pragma once
#include "CoreMinimal.h"
#include "IsBuriedChangedEventDelegate.h"
#include "PhysicsComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformableInterfaceT2 -FallbackName=DeformableInterfaceT2
#include "SignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformationParamsT2 -FallbackName=DeformationParamsT2
#include "DeformableInterfaceT2.h"
#include "DeformationParamsT2.h"
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
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
    UFUNCTION()
    void OnRep_Buried(bool previousIsBuried);
    
public:
    UFUNCTION()
    void OnDeformationComplete(const FDeformationParamsT2& deformationParams);
    
    UFUNCTION(BlueprintPure)
    bool IsTerrainBuried();
    
    UFUNCTION(BlueprintPure)
    bool GetIsBuried() const;
    
    
    // Fix for true pure virtual functions not being implemented
};

