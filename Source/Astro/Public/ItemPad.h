#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SceneComponent -FallbackName=SceneComponent
#include "SignalDelegate.h"
#include "DeformableInterfaceT2.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformableInterfaceT2 -FallbackName=DeformableInterfaceT2
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=Terrain2 -ObjectName=DeformationParamsT2 -FallbackName=DeformationParamsT2
#include "DeformationParamsT2.h"
#include "ItemPad.generated.h"

class AItemPadActor;
class UPrimitiveComponent;
class UAstroSaveCustomArchiveProxy;
class UItemPad;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UItemPad : public USceneComponent, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ManuallyReplicatePadTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItemPadActor> PadClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnSpawnPad;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSignal OnDestroyPad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Pad, meta=(AllowPrivateAccess=true))
    AItemPadActor* Pad;
    
    UItemPad();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void StartInWorld();
    
public:
    UFUNCTION(BlueprintCallable)
    void SpawnPad(bool withTool, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
private:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
    UFUNCTION()
    void ReleaseFromSlot(bool NewOwner);
    
    UFUNCTION()
    void PlaceInSlot();
    
    UFUNCTION()
    void PickUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION()
    void OnRep_Pad();
    
public:
    UFUNCTION()
    void OnDeformationComplete(const FDeformationParamsT2& deformationParams);
    
private:
    UFUNCTION()
    void MotionStateChanged();
    
    UFUNCTION()
    void EmplaceInSlot();
    
    UFUNCTION()
    void DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
public:
    UFUNCTION(BlueprintPure)
    static UItemPad* ActorItemPad(AActor* Actor);
    
    
    // Fix for true pure virtual functions not being implemented
};

