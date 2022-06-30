#pragma once
#include "CoreMinimal.h"
#include "ETetherAttachmentType.h"
#include "Components/ActorComponent.h"
#include "LinearAttachPoint.h"
#include "CircularAttachPoint.h"
#include "OxygenChangeDelegateDelegate.h"
#include "SlotReference.h"
#include "VampireAttachmentEntry.h"
#include "ExplicitOxygenConnections.h"
#include "UObject/NoExportTypes.h"
#include "TetherAttachComponent.generated.h"

class UTetherAttachComponent;
class USceneComponent;
class UTetherNetwork;
class UOxygenatorComponent;
class AActor;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UTetherAttachComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateTetherAttachPowerFlow, float, PowerFlow);

    UPROPERTY(BlueprintAssignable)
    FUpdateTetherAttachPowerFlow OnUpdateTetherAttachPowerFlow;

    UPROPERTY(BlueprintAssignable)
    FOxygenChangeDelegate OnOxygenChange;

    UPROPERTY(BlueprintAssignable)
    FOxygenChangeDelegate OnDirectOrConnectedOxygenChange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta = (AllowPrivateAccess = true))
    bool CanAttach;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AttachToConnections;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HaveConnectedOxygen;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool HaveDirectOrConnectedOxygen;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference Slot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FLinearAttachPoint> LinearAttachPoints;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FCircularAttachPoint> CircularAttachPoints;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    TArray<USceneComponent *> SingularAttachPoints;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float TetherAttachDistance;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UTetherNetwork *Network;

    UPROPERTY(Export, SaveGame, Transient)
    TArray<UTetherAttachComponent *> ConnectedTetherPosts;

private:
    UPROPERTY(SaveGame)
    TArray<FVampireAttachmentEntry> VampireAttachments;

    UPROPERTY(Export, Transient)
    TArray<UOxygenatorComponent *> LinkedOxygenators;

    UPROPERTY(Export, Transient)
    UOxygenatorComponent *BuiltInOxygenator;

    UPROPERTY(SaveGame)
    TMap<UTetherAttachComponent *, FExplicitOxygenConnections> ExplicitOxygenConnections;

    UPROPERTY(EditDefaultsOnly)
    ETetherAttachmentType TetherAttachmentType;

    UPROPERTY(EditDefaultsOnly)
    bool bConnectToCharactersOnlyWithoutExternalOxygenator;

public:
    UTetherAttachComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateExplicitNetwork();

    UFUNCTION()
    void TeardownLinkToOxygenator(UOxygenatorComponent *oxygenator);

    UFUNCTION(BlueprintCallable)
    void SetCanAttach(bool NewCanAttach, bool ForceUpdate, bool fromSave);

private:
    UFUNCTION()
    void OnOwnerMotionStateChanged();

public:
    UFUNCTION()
    void OnOwnerDestroy(AActor *Actor);

private:
    UFUNCTION()
    void OnBuiltInOxygenatorOxygenChanged(UOxygenatorComponent *oxygenator);

    UFUNCTION()
    void OnBuiltInOxygenatorDestroyed(UOxygenatorComponent *oxygenator);

public:
    UFUNCTION(BlueprintPure)
    ETetherAttachmentType GetTetherAttachmentType();

    UFUNCTION(BlueprintPure)
    float GetPowerFlowOnVampireConnections();

    UFUNCTION(BlueprintCallable)
    FVector GetAttachPoint(FSlotReference SlotRef, const FVector &InLocation, bool allowConnections);

    UFUNCTION(BlueprintPure)
    static UTetherAttachComponent *GetActorTetherAttachComponent(AActor *Actor);

    UFUNCTION(BlueprintPure)
    static UTetherAttachComponent *GetActorHierarchyTetherAttachComponent(AActor *Actor);
};
