#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "PlayerProximityTickComponent.generated.h"

class AActor;
class UPlayerProximityTickComponent;
class UShapeComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPlayerProximityTickComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerProximityTickDisableTickEvent);

    UPROPERTY(EditAnywhere)
    float InitialSphereRadius;

    UPROPERTY(BlueprintAssignable)
    FPlayerProximityTickDisableTickEvent OnDisableTick;

protected:
    UPROPERTY(EditAnywhere)
    uint8 bManageActorTick : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bCanIgnoreCreativeModeHazardInvisibility : 1;

    UPROPERTY(EditDefaultsOnly)
    uint8 bAutoHandleCriticalComponents : 1;

    UPROPERTY()
    TArray<AActor *> OverlappingPlayers;

    UPROPERTY(Export)
    UShapeComponent *ProximityShape;

    UPROPERTY(Export)
    TArray<UActorComponent *> ManagedComponents;

    UPROPERTY(Export, Transient)
    TArray<UActorComponent *> AutoManagedComponents;

    UPROPERTY(Transient)
    TArray<uint8> AutoManagedComponentFlags;

public:
    UPlayerProximityTickComponent();
    UFUNCTION(BlueprintCallable)
    void SetProximitySphere(float Radius);

    UFUNCTION(BlueprintCallable)
    void SetProximityShape(UShapeComponent *inProximityShape);

protected:
    UFUNCTION()
    void OnTrackedPlayerDestroyed(AActor *DestroyedActor);

public:
    UFUNCTION(BlueprintPure)
    TArray<AActor *> GetOverlappingPlayers();

    UFUNCTION(BlueprintPure)
    static UPlayerProximityTickComponent *GetActorPlayerProximityTickComponent(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static TArray<AActor *> GetActorOverlappingPlayers(AActor *Actor);

protected:
    UFUNCTION()
    void EndOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

public:
    UFUNCTION(BlueprintCallable)
    void CheckAndDisableTick();

protected:
    UFUNCTION()
    void BeginOverlap(UPrimitiveComponent *OverlappedComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &OverlapInfo);

public:
    UFUNCTION(BlueprintCallable)
    void AddManagedComponents(const TArray<UActorComponent *> &Components);

    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent *Component);
};
