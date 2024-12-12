#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "ShelterTutorialComponent.generated.h"

class APhysicalItem;
class AResourceInfo;
class ASlotConnection;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UShelterTutorialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableTutorialCompleteEvent);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> GrabSlotIndicator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> AttachSlotIndicator;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableTutorialCompleteEvent OnCableTutorialComplete;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CableTutorialIsComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResourceInfo*> ShelterCableIndicators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AResourceInfo*> PlatformCableIndicators;
    
public:
    UShelterTutorialComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopCableTutorial();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupCableTutorial(TArray<FSlotReference> shelterCableSlots, APhysicalItem* Platform);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetCableTutorialKey(FName tutorialKey);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable);
    
};

