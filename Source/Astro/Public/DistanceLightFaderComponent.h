#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "DistanceLightFaderComponent.generated.h"

class ULightComponent;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UDistanceLightFaderComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLightChangedFromDistanceFade, const bool, IsVisible);

    UPROPERTY(Replicated)
    bool bIsUsingVirtualLight;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float LightIntensity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LightSquaredDist;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool LightVisible;

    UPROPERTY(Replicated)
    uint8 REP_LightWantsToBeOn;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    ULightComponent *LightComponent;

    UPROPERTY(EditDefaultsOnly, Export)
    USceneComponent *WithVisibilityComponent;

    UPROPERTY(BlueprintAssignable)
    FLightChangedFromDistanceFade OnLightChangedFromDistanceFade;

    UDistanceLightFaderComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void UpdateLightVisibility(bool setVisible);

    UFUNCTION(BlueprintCallable)
    void UpdateLightIntensity(float NewIntensity);

    UFUNCTION(BlueprintCallable)
    void UpdateLightFadeWithVisibility(FVector otherObjectLocation, bool setVisible);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthoritySetLightWantsToBeOn(const bool wantsToBeOn);
};
