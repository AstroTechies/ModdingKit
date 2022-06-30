#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "IndicatorCollection.h"
#include "Engine/EngineTypes.h"
#include "SlotReference.h"
#include "CableExtenderTutorialComponent.generated.h"

class AResourceInfo;
class UItemType;
class USphereComponent;
class APhysicalItem;
class UPrimitiveComponent;
class AActor;
class ASlotConnection;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCableExtenderTutorialComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableReleasedEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableExtenderTutorialCompleteEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableExtendedEvent);

    UPROPERTY(EditAnywhere)
    float CableSocketSearchRadius;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AResourceInfo> SocketIndicatorType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<AResourceInfo> ExtenderIndicatorType;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UItemType> ExtenderItemType;

protected:
    UPROPERTY(BlueprintAssignable)
    FCableExtendedEvent OnCableExtended;

    UPROPERTY(BlueprintAssignable)
    FCableReleasedEvent OnCableReleased;

    UPROPERTY(BlueprintAssignable)
    FCableExtenderTutorialCompleteEvent OnCableExtenderTutorialComplete;

private:
    UPROPERTY(Export)
    USphereComponent *CollisionSphere;

    UPROPERTY()
    TMap<TWeakObjectPtr<APhysicalItem>, FIndicatorCollection> CurrentIndicators;

public:
    UCableExtenderTutorialComponent();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void StopTutorial();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetupTutorial();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetExtenderTutorialKey(FName tutorialKey);

protected:
    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

    UFUNCTION()
    void OnCableTargetReleased(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection *cable);

    UFUNCTION()
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection *cable);
};
