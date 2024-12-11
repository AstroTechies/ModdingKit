#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ItemPadActor.generated.h"

class UItemPad;
class UPrimitiveComponent;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API AItemPadActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* BaseLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, meta=(AllowPrivateAccess=true))
    UItemPad* OwnerComponent;
    
    AItemPadActor(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShouldDestroyOnPickup();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawn(bool withTool, UPrimitiveComponent* Component, const FVector& Point, const FVector& Normal);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOwnerDestroyed(AActor* deletingOwner);
    
};

