#pragma once
#include "CoreMinimal.h"
#include "EStationLoadingState.h"
#include "EStationStopState.h"
#include "RailPostComponent.h"
#include "SignalDelegate.h"
#include "RailPostStationComponent.generated.h"

class ARailCarBase;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URailPostStationComponent : public URailPostComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnStationSettingsChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CarPushSlotRuleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CarPullSlotRuleName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_StationSettings, meta=(AllowPrivateAccess=true))
    EStationStopState StopMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_StationSettings, meta=(AllowPrivateAccess=true))
    EStationLoadingState LoadMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentInternalConnectionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARailCarBase* lastStoppedCar;
    
public:
    URailPostStationComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_StationSettings();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStationStopState GetCurrentStopMode();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EStationLoadingState GetCurrentLoadMode();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetStopMode(EStationStopState Mode);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLoadMode(EStationLoadingState Mode);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityDispatchStoppedCar(bool bToLeft);
    
};

