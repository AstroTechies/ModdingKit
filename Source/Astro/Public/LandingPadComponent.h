#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SlotReference.h"
#include "Components/SceneComponent.h"
#include "LandingPadComponent.generated.h"

class APhysicalItem;
class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API ULandingPadComponent : public USceneComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<AActor> PlanetMarkerType;

    UPROPERTY(EditDefaultsOnly)
    float MaximumOperationalTilt;

    UPROPERTY(EditDefaultsOnly)
    float SkyObstructionTestRadius;

    UPROPERTY(EditDefaultsOnly)
    FName LandingPadSlotName;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    FSlotReference LandingPadSlotRef;

    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    AActor *PlanetMarker;

    UPROPERTY(Transient)
    APhysicalItem *OwnerItem;

    UPROPERTY(SaveGame)
    uint8 bDeployed : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bSkipOrientationValidation : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAutomaticDeployment : 1;

    UPROPERTY(SaveGame)
    uint8 bSkyObstructed : 1;

public:
    ULandingPadComponent();

protected:
    UFUNCTION()
    void OnOwnerItemMotionStateChanged();

    UFUNCTION()
    void OnItemSetInLandingPadSlot(APhysicalItem *Item);

    UFUNCTION()
    void OnItemRemovedFromLandingPadSlot(APhysicalItem *Item);

public:
    UFUNCTION(BlueprintPure)
    bool IsOccupied() const;

    UFUNCTION(BlueprintPure)
    bool CanDeploy() const;

    UFUNCTION(BlueprintPure)
    bool CanCheckObstruction() const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityTeardownLandingPad();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthorityDeployLandingPad();
};
