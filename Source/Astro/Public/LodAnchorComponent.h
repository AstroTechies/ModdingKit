#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "Components/ActorComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "DeformationParamsT2.h"
#include "ELodAnchorState.h"
#include "LodAnchorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API ULodAnchorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference BeaconReference;
    
private:
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnReplicated_IsAnchored, meta=(AllowPrivateAccess=true))
    ELodAnchorState IsAnchored;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsActivated: 1;
    
public:
    ULodAnchorComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    bool UpdateInternal(const FVector& NewPosition);
    
    UFUNCTION(BlueprintCallable)
    void ToggleActivated();
    
    UFUNCTION(BlueprintCallable)
    void ShowPreviz(bool show);
    
    UFUNCTION(BlueprintCallable)
    void SetBeaconVisibility(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetActivated(bool makeActive, bool ForceUpdate);
    
private:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerChangeActivated(bool makeActive, bool ForceUpdate);
    
    UFUNCTION(BlueprintCallable)
    void OnReplicated_IsAnchored();
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleDeformed(const FDeformationParamsT2& params);
    
};

