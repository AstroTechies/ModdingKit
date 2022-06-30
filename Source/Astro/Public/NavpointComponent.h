#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Navpoint.h"
#include "UObject/NoExportTypes.h"
#include "EnableSignalDelegate.h"
#include "NavpointComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UNavpointComponent : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FGuid NavpointID;

    UPROPERTY(EditDefaultsOnly)
    FNavpoint StartingNavpoint;

    UPROPERTY(EditDefaultsOnly, SaveGame)
    uint8 bShouldRegisterNavpoint : 1;

    UPROPERTY(BlueprintAssignable)
    FEnableSignal OnNavpointEnabledChanged;

public:
    UNavpointComponent();

protected:
    UFUNCTION()
    void HandleNavpointOwnershipChanged(const FGuid &NewNavpointID);

    UFUNCTION()
    void HandleNavpointEnabled(const FGuid &NewNavpointID);

    UFUNCTION()
    void HandleNavpointDisabled(const FGuid &NewNavpointID);

public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetShouldRegisterNavpoint(bool bShouldRegister);
};
