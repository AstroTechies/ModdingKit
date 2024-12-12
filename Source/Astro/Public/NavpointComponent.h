#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "EnableSignalDelegate.h"
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
    UNavpointComponent(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void HandleNavpointOwnershipChanged(const FGuid& NewNavpointID);
    
    UFUNCTION(BlueprintCallable)
    void HandleNavpointEnabled(const FGuid& NewNavpointID);
    
    UFUNCTION(BlueprintCallable)
    void HandleNavpointDisabled(const FGuid& NewNavpointID);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetShouldRegisterNavpoint(bool bShouldRegister);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetNavpointEnabled(bool bNavpointEnabled);
    
};

