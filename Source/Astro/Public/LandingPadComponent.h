#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "SlotReference.h"
#include "LandingPadComponent.generated.h"

class AActor;
class APhysicalItem;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULandingPadComponent : public USceneComponent {
    GENERATED_BODY()
public:
protected:
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
    ULandingPadComponent();
protected:
    UFUNCTION()
    void OnOwnerItemMotionStateChanged();
    
    UFUNCTION()
    void OnItemSetInLandingPadSlot(APhysicalItem* Item);
    
    UFUNCTION()
    void OnItemRemovedFromLandingPadSlot(APhysicalItem* Item);
    
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

