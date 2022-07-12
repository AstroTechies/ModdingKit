#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "TetherPostComponent.generated.h"

class UTetherAttachComponent;
class UPowerComponent;
class UInstancedStaticMeshComponent;
class UDistanceLightFaderComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTetherPostComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Placing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Placed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* IndicatorAttach;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPowerComponent* PowerComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* AttachComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UInstancedStaticMeshComponent* IndicatorInstancedMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDistanceLightFaderComponent* LightFader;
    
    UTetherPostComponent();
    UFUNCTION(BlueprintCallable)
    void SetPlacing(bool newPlacing);
    
private:
    UFUNCTION()
    void OnOwnerPlacedInSlot();
    
public:
    UFUNCTION(BlueprintCallable)
    void BreakTethers();
    
    UFUNCTION(BlueprintCallable)
    void AttachTethers(bool fromSave);
    
};

