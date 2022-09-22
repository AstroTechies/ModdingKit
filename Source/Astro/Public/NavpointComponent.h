#pragma once
#include "CoreMinimal.h"
#include "EnableSignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
#include "Navpoint.h"
#include "NavpointComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UNavpointComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid NavpointID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNavpoint StartingNavpoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bShouldRegisterNavpoint: 1;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnableSignal OnNavpointEnabledChanged;
    
public:
    UNavpointComponent();
protected:
    UFUNCTION()
    void HandleNavpointOwnershipChanged(const FGuid& NewNavpointID);
    
    UFUNCTION()
    void HandleNavpointEnabled(const FGuid& NewNavpointID);
    
    UFUNCTION()
    void HandleNavpointDisabled(const FGuid& NewNavpointID);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetShouldRegisterNavpoint(bool bShouldRegister);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetNavpointEnabled(bool bNavpointEnabled);
    
};

