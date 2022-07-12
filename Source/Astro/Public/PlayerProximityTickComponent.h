#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "PlayerProximityTickComponent.generated.h"

class UPrimitiveComponent;
class AActor;
class UShapeComponent;
class UPlayerProximityTickComponent;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UShapeComponent* ProximityShape;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> ManagedComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UActorComponent*> AutoManagedComponents;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<uint8> AutoManagedComponentFlags;
    
public:
    UPlayerProximityTickComponent();
    UFUNCTION(BlueprintCallable)
    void SetProximitySphere(float Radius);
    
    UFUNCTION(BlueprintCallable)
    void SetProximityShape(UShapeComponent* inProximityShape);
    
protected:
    UFUNCTION()
    void OnTrackedPlayerDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintPure)
    TArray<AActor*> GetOverlappingPlayers();
    
    UFUNCTION(BlueprintPure)
    static UPlayerProximityTickComponent* GetActorPlayerProximityTickComponent(AActor* Actor);
    
    UFUNCTION(BlueprintPure)
    static TArray<AActor*> GetActorOverlappingPlayers(AActor* Actor);
    
protected:
    UFUNCTION()
    void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
public:
    UFUNCTION(BlueprintCallable)
    void CheckAndDisableTick();
    
protected:
    UFUNCTION()
    void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& OverlapInfo);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddManagedComponents(const TArray<UActorComponent*>& Components);
    
    UFUNCTION(BlueprintCallable)
    void AddManagedComponent(UActorComponent* Component);
    
};

