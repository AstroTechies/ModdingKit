#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "PlayerToolComponent.generated.h"

class AActor;
class USceneComponent;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UPlayerToolComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    FTransform TableTransform;

    UPROPERTY(EditAnywhere)
    FName AttachBoneName;

    UPROPERTY(EditAnywhere)
    bool UnencapsulateChildrenWhileActive;

    UPROPERTY(EditAnywhere)
    bool HeldTool;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *AttachLocationComponent;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TableComponent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CrackedValue;

private:
    UPROPERTY(ReplicatedUsing = OnRep_Activated)
    uint8 m_activated : 1;

public:
    UPlayerToolComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_Activated();

    UFUNCTION()
    void OnControlDeactivate();

    UFUNCTION()
    void OnControlActivate();

    UFUNCTION()
    void OnActorClicked(AActor *Actor, FKey Key);
};
