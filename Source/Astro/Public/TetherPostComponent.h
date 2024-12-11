#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TetherPostComponent.generated.h"

class UDistanceLightFaderComponent;
class UInstancedStaticMeshComponent;
class UPowerComponent;
class UTetherAttachComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTetherPostComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Placing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Placed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* IndicatorAttach;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* AttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* IndicatorInstancedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDistanceLightFaderComponent* LightFader;
    
    UTetherPostComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetPlacing(bool newPlacing);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOwnerPlacedInSlot();
    
public:
    UFUNCTION(BlueprintCallable)
    void BreakTethers();
    
    UFUNCTION(BlueprintCallable)
    void AttachTethers(bool fromSave);
    
};

