#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnResourceSlotFullDelegate.h"
#include "OnResourceStoredDelegate.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "ResourceCacheComponent.generated.h"

class AAstroCharacter;
class UDeformEventReceiver;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UResourceCacheComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference ResourceOutputSlot;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResourceSlotFull OnResourceSlotFull;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResourceStored OnResourceStored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* DeformEventReceiver;
    
    UResourceCacheComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SwapResources(TSubclassOf<UItemType> MineralType);
    
    UFUNCTION(BlueprintCallable)
    void StoreResource(TSubclassOf<UItemType> MineralType, int32 Amount);
    
    UFUNCTION(BlueprintCallable)
    void OnAcceptResource(TSubclassOf<UItemType> Type, int32 Amount);
    
protected:
    UFUNCTION(BlueprintCallable)
    AAstroCharacter* GetCharacter();
    
public:
    UFUNCTION(BlueprintCallable)
    void CacheResources();
    
protected:
    UFUNCTION(BlueprintCallable)
    bool ApplyPower(float Amount);
    
    UFUNCTION(BlueprintCallable)
    bool ApplyOxygen(int32 Amount);
    
};

