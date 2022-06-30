#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "ItemPadActor.generated.h"

class UItemPad;
class USceneComponent;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AItemPadActor : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *BaseLocation;

    UPROPERTY(BlueprintReadWrite, Export, SaveGame, meta = (AllowPrivateAccess = true))
    UItemPad *OwnerComponent;

    AItemPadActor();
    UFUNCTION(BlueprintNativeEvent)
    bool ShouldDestroyOnPickup();

    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawn(bool withTool, UPrimitiveComponent *Component, const FVector &Point, const FVector &Normal);

private:
    UFUNCTION()
    void OnOwnerDestroyed(AActor *deletingOwner);
};
