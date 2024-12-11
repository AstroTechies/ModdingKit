#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "PlayerProximityTickComponent.generated.h"

class AActor;
class UPlayerProximityTickComponent;
class UPrimitiveComponent;
class UShapeComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UPlayerProximityTickComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPlayerProximityTickDisableTickEvent);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialSphereRadius;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerProximityTickDisableTickEvent OnDisableTick;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bManageActorTick: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanIgnoreCreativeModeHazardInvisibility: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoHandleCriticalComponents: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlappingPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* ProximityShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> ManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> AutoManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint8> AutoManagedComponentFlags;
    
public:
    UPlayerProximityTickComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetProximitySphere(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void SetProximityShape(UShapeComponent* inProximityShape);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTrackedPlayerDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AActor*> GetOverlappingPlayers();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPlayerProximityTickComponent* GetActorPlayerProximityTickComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<AActor*> GetActorOverlappingPlayers(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable)
    void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void CheckAndDisableTick();
    
protected:
    UFUNCTION(BlueprintCallable)
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddManagedComponents(const TArray<UActorComponent*>& Components);
    
    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent* Component);
    
};

