#pragma once
#include "CoreMinimal.h"
#include "ELogisticsComplexChannel.h"
#include "EPlanetIdentifier.h"
#include "MegaStructure.h"
#include "OnShuttleDockedAtOtherComplexDelegate.h"
#include "OnTargetShuttleRemovedFromOtherComplexDelegate.h"
#include "SignalDelegate.h"
#include "LogisticsComplex.generated.h"

class APhysicalItem;
class ULandingPadComponent;

UCLASS(Blueprintable)
class ASTRO_API ALogisticsComplex : public AMegaStructure {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnLogisticsComplexSetupComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShuttleDockedAtOtherComplex OnShuttleDockedAtOtherComplex;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTargetShuttleRemovedFromOtherComplex OnTargetShuttleRemovedFromOtherComplex;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LogistcsComplexSetupComplete, meta=(AllowPrivateAccess=true))
    uint8 bLogistcsComplexSetupComplete: 1;
    
public:
    ALogisticsComplex(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void RecallLostShuttle(const ULandingPadComponent* inLandingPad);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_LogistcsComplexSetupComplete() const;
    
public:
    UFUNCTION(BlueprintCallable)
    static EPlanetIdentifier IncrementSelectedPlanetIndex_Helper(const int32 inCurrentIndex, const TArray<bool>& inPlanetsWithLogisticsComplex, const TArray<EPlanetIdentifier>& inPlanetIdentifierList);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsLogisticsComplexReady() const;
    
    UFUNCTION(BlueprintCallable)
    static EPlanetIdentifier DecrementSelectedPlanetIndex_Helper(const int32 inCurrentIndex, const TArray<bool>& inPlanetsWithLogisticsComplex, const TArray<EPlanetIdentifier>& inPlanetIdentifierList);
    
    UFUNCTION(BlueprintCallable)
    void CallShuttle(const ULandingPadComponent* inLandingPad);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityUnbindEventsFromSavedLandingPad();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLogisticsComplexReady();
    
private:
    UFUNCTION(BlueprintCallable)
    void AuthorityOnTargetShuttleRemovedFromOtherComplex(APhysicalItem* inItem);
    
    UFUNCTION(BlueprintCallable)
    void AuthorityOnShuttleDockedAtOtherComplex(APhysicalItem* inItem);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityBindToDesiredLandingPadAndCheckForShuttle(const EPlanetIdentifier inPlanetId, const ELogisticsComplexChannel InChannel);
    
};

