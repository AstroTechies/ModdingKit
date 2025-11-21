#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ELogisticsComplexChannel.h"
#include "EPlanetIdentifier.h"
#include "EShuttleAutomationRule.h"
#include "EShuttleSlotOrgRule.h"
#include "SignalDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "LandingPadComponent.generated.h"

class AActor;
class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULandingPadComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnTargetPlanetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnShuttleAutomationRuleChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnShuttleSlotOrgRuleChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnInternalPlanetChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnInternalShuttleAutomationRuleChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnInternalShuttleSlotOrgRuleChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    ELogisticsComplexChannel LandingPadChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_PlanetChanged, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier TargetPlanetId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ShuttleAutomationRuleChanged, meta=(AllowPrivateAccess=true))
    EShuttleAutomationRule ShuttleAutomationRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_ShuttleSlotOrgRuleChanged, meta=(AllowPrivateAccess=true))
    EShuttleSlotOrgRule ShuttleSlotOrgRule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> PlanetMarkerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumOperationalTilt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SkyObstructionTestRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LandingPadSlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSlotReference LandingPadSlotRef;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AActor* PlanetMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwnerItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bDeployed: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSkipOrientationValidation: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutomaticDeployment: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bSkyObstructed: 1;
    
public:
    ULandingPadComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetTargetPlanetId(const EPlanetIdentifier InTargetPlanetId);
    
    UFUNCTION(BlueprintCallable)
    void SetLandingPadShuttleSlotOrgRule(const EShuttleSlotOrgRule InShuttleSlotOrgRule);
    
    UFUNCTION(BlueprintCallable)
    void SetLandingPadShuttleAutomationRule(const EShuttleAutomationRule InShuttleAutomationRule);
    
    UFUNCTION(BlueprintCallable)
    void SetLandingPadChannel(const ELogisticsComplexChannel InLandingPadChannel);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ShuttleSlotOrgRuleChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ShuttleAutomationRuleChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void OnRep_PlanetChanged() const;
    
    UFUNCTION(BlueprintCallable)
    void OnOwnerItemMotionStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnItemSetInLandingPadSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnItemRemovedFromLandingPadSlot(APhysicalItem* Item);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsOccupied() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EPlanetIdentifier GetTargetPlanetId() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EShuttleSlotOrgRule GetLandingPadShuttleSlotOrgRule() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EShuttleAutomationRule GetLandingPadShuttleAutomationRule() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELogisticsComplexChannel GetLandingPadChannel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanDeploy() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanCheckObstruction() const;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTeardownLandingPad();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityDeployLandingPad();
    
};

