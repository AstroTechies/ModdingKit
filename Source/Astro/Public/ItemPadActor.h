#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ItemPadActor.generated.h"

class UPrimitiveComponent;
class USceneComponent;
class UItemPad;

UCLASS(Blueprintable)
class ASTRO_API AItemPadActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* BaseLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, meta=(AllowPrivateAccess=true))
    UItemPad* OwnerComponent;
    
    AItemPadActor();
    UFUNCTION(BlueprintNativeEvent)
    bool ShouldDestroyOnPickup();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawn(bool withTool, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
private:
    UFUNCTION()
    void OnOwnerDestroyed(AActor* deletingOwner);
    
};

