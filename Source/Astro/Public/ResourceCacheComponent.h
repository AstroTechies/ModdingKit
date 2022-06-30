#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "OnResourceStoredDelegate.h"
#include "OnResourceSlotFullDelegate.h"
#include "ResourceCacheComponent.generated.h"

class UDeformEventReceiver;
class AAstroCharacter;
class UItemType;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UResourceCacheComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference ResourceOutputSlot;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnResourceSlotFull OnResourceSlotFull;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FOnResourceStored OnResourceStored;

    UPROPERTY(Export)
    UDeformEventReceiver *DeformEventReceiver;

    UResourceCacheComponent();
    UFUNCTION(BlueprintCallable)
    void SwapResources(TSubclassOf<UItemType> MineralType);

    UFUNCTION(BlueprintCallable)
    void StoreResource(TSubclassOf<UItemType> MineralType, int32 Amount);

    UFUNCTION()
    void OnAcceptResource(TSubclassOf<UItemType> Type, int32 Amount);

protected:
    UFUNCTION()
    AAstroCharacter *GetCharacter();

public:
    UFUNCTION(BlueprintCallable)
    void CacheResources();

protected:
    UFUNCTION()
    bool ApplyPower(float Amount);

    UFUNCTION()
    bool ApplyOxygen(int32 Amount);
};
