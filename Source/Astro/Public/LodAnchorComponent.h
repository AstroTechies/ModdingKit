#pragma once
#include "CoreMinimal.h"
#include "DeformationParamsT2.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ELodAnchorState.h"
#include "LodAnchorComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API ULodAnchorComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FComponentReference BeaconReference;

private:
    UPROPERTY(ReplicatedUsing = OnReplicated_IsAnchored)
    ELodAnchorState IsAnchored;

    UPROPERTY(SaveGame)
    uint8 bIsActivated : 1;

public:
    ULodAnchorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    bool UpdateInternal(const FVector &NewPosition);

    UFUNCTION(BlueprintCallable)
    void ToggleActivated();

    UFUNCTION(BlueprintCallable)
    void ShowPreviz(bool show);

    UFUNCTION(BlueprintCallable)
    void SetBeaconVisibility(bool Enabled);

    UFUNCTION(BlueprintCallable)
    void SetActivated(bool makeActive, bool ForceUpdate);

private:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerChangeActivated(bool makeActive, bool ForceUpdate);

    UFUNCTION()
    void OnReplicated_IsAnchored();

public:
    UFUNCTION(BlueprintCallable)
    void HandleDeformed(const FDeformationParamsT2 &params);
};
