#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "DeformableInterfaceT2.h"
#include "DeformationParamsT2.h"
#include "SignalDelegate.h"
#include "Templates/SubclassOf.h"
#include "ItemPad.generated.h"

class AActor;
class AItemPadActor;
class UAstroSaveCustomArchiveProxy;
class UItemPad;
class UPrimitiveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UItemPad : public USceneComponent, public IDeformableInterfaceT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoSpawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HandleItemPadDugUp;
    
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
    
    UItemPad(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    UFUNCTION(BlueprintCallable)
    void StartInWorld();
    
public:
    UFUNCTION(BlueprintCallable)
    void SpawnPad(bool withTool, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
private:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
    UFUNCTION(BlueprintCallable)
    void ReleaseFromSlot(bool NewOwner);
    
    UFUNCTION(BlueprintCallable)
    void PlaceInSlot();
    
    UFUNCTION(BlueprintCallable)
    void PickUpFromWorld(bool PhysicalMovement);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Pad();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnDeformationComplete(const FDeformationParamsT2& deformationParams);
    
private:
    UFUNCTION(BlueprintCallable)
    void MotionStateChanged();
    
    UFUNCTION(BlueprintCallable)
    void EmplaceInSlot();
    
    UFUNCTION(BlueprintCallable)
    void DropInWorld(UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemPad* ActorItemPad(AActor* Actor);
    

    // Fix for true pure virtual functions not being implemented
};

