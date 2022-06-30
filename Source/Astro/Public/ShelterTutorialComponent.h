#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "ShelterTutorialComponent.generated.h"

class AResourceInfo;
class APhysicalItem;
class ASlotConnection;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UShelterTutorialComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableTutorialCompleteEvent);

    UPROPERTY(EditAnywhere)
    TSubclassOf<AResourceInfo> GrabSlotIndicator;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AResourceInfo> AttachSlotIndicator;

    UPROPERTY(BlueprintAssignable)
    FCableTutorialCompleteEvent OnCableTutorialComplete;

protected:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    bool CableTutorialIsComplete;

private:
    UPROPERTY()
    TArray<AResourceInfo *> ShelterCableIndicators;

    UPROPERTY()
    TArray<AResourceInfo *> PlatformCableIndicators;

public:
    UShelterTutorialComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(TArray<FSlotReference> shelterCableSlots, APhysicalItem *Platform);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCableTutorialKey(FName tutorialKey);

protected:
    UFUNCTION()
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection *cable);
};
