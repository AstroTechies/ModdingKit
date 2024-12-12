#pragma once
#include "CoreMinimal.h"
#include "RailPostComponent.h"
#include "RailPostTurntableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API URailPostTurntableComponent : public URailPostComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 CurrentCarSlotConnectionState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_CurrentConnection, meta=(AllowPrivateAccess=true))
    int32 CurrentCarSlotConnectionID;
    
public:
    URailPostTurntableComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentConnection();
    
    UFUNCTION(BlueprintCallable)
    void HandleUse();
    
public:
    UFUNCTION(BlueprintCallable)
    bool AuthoritySetInternalConnectionState(int32 State);
    
};

