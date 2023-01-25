#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "IndicatorCollection.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "CableExtenderTutorialComponent.generated.h"

class AActor;
class APhysicalItem;
class AResourceInfo;
class ASlotConnection;
class UItemType;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UCableExtenderTutorialComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableReleasedEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableExtenderTutorialCompleteEvent);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCableExtendedEvent);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CableSocketSearchRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> SocketIndicatorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AResourceInfo> ExtenderIndicatorType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ExtenderItemType;
    
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableExtendedEvent OnCableExtended;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableReleasedEvent OnCableReleased;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCableExtenderTutorialCompleteEvent OnCableExtenderTutorialComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* CollisionSphere;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
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
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnCableTargetReleased(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCablePulled(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableDestroyed(FSlotReference cableSlot, ASlotConnection* cable);
    
    UFUNCTION(BlueprintCallable)
    void OnCableConnected(FSlotReference cableSlot, ASlotConnection* cable);
    
};

