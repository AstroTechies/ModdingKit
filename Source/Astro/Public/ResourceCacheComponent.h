#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "SlotReference.h"
#include "OnResourceSlotFullDelegate.h"
#include "OnResourceStoredDelegate.h"
#include "ResourceCacheComponent.generated.h"

class UItemType;
class AAstroCharacter;
class UDeformEventReceiver;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UDeformEventReceiver* DeformEventReceiver;
    
    UResourceCacheComponent();
    UFUNCTION(BlueprintCallable)
    void SwapResources(TSubclassOf<UItemType> MineralType);
    
    UFUNCTION(BlueprintCallable)
    void StoreResource(TSubclassOf<UItemType> MineralType, int32 Amount);
    
    UFUNCTION()
    void OnAcceptResource(TSubclassOf<UItemType> Type, int32 Amount);
    
protected:
    UFUNCTION()
    AAstroCharacter* GetCharacter();
    
public:
    UFUNCTION(BlueprintCallable)
    void CacheResources();
    
protected:
    UFUNCTION()
    bool ApplyPower(float Amount);
    
    UFUNCTION()
    bool ApplyOxygen(int32 Amount);
    
};

