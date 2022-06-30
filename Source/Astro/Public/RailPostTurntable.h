#pragma once
#include "CoreMinimal.h"
#include "RailPostBase.h"
#include "RailPostTurntable.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARailPostTurntable : public ARailPostBase
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(SaveGame)
    int32 CurrentCarSlotConnectionState;

    UPROPERTY(Replicated, SaveGame)
    int32 CurrentCarSlotConnectionID;

public:
    ARailPostTurntable();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void AuthoritySetCarSlotConnectionState(int32 State, bool ForceUpdate);
};
