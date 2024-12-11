#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "CircularAttachPoint.h"
#include "ETetherAttachmentType.h"
#include "ExplicitOxygenConnections.h"
#include "LinearAttachPoint.h"
#include "OxygenChangeDelegateDelegate.h"
#include "SlotReference.h"
#include "VampireAttachmentEntry.h"
#include "TetherAttachComponent.generated.h"

class AActor;
class UOxygenatorComponent;
class USceneComponent;
class UTetherAttachComponent;
class UTetherNetwork;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTetherAttachComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateTetherAttachPowerFlow, float, PowerFlow);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FUpdateTetherAttachPowerFlow OnUpdateTetherAttachPowerFlow;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenChangeDelegate OnOxygenChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOxygenChangeDelegate OnDirectOrConnectedOxygenChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CanAttach;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachToConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HaveConnectedOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HaveDirectOrConnectedOxygen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLinearAttachPoint> LinearAttachPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCircularAttachPoint> CircularAttachPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> SingularAttachPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TetherAttachDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TetherAttachedExtraDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTetherNetwork* Network;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTetherAttachComponent*> ConnectedTetherPosts;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVampireAttachmentEntry> VampireAttachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UOxygenatorComponent*> LinkedOxygenators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UOxygenatorComponent* BuiltInOxygenator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UTetherAttachComponent*, FExplicitOxygenConnections> ExplicitOxygenConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETetherAttachmentType TetherAttachmentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConnectToCharactersOnlyWithoutExternalOxygenator;
    
public:
    UTetherAttachComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void UpdateExplicitNetwork();
    
    UFUNCTION(BlueprintCallable)
    void TeardownLinkToOxygenator(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable)
    void SetCanAttach(bool NewCanAttach, bool ForceUpdate, bool fromSave);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOwnerMotionStateChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnOwnerDestroy(AActor* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnBuiltInOxygenatorOxygenChanged(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable)
    void OnBuiltInOxygenatorDestroyed(UOxygenatorComponent* oxygenator);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETetherAttachmentType GetTetherAttachmentType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPowerFlowOnVampireConnections();
    
    UFUNCTION(BlueprintCallable)
    FVector GetAttachPoint(FSlotReference SlotRef, const FVector& InLocation, bool allowConnections);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTetherAttachComponent* GetActorTetherAttachComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UTetherAttachComponent* GetActorHierarchyTetherAttachComponent(AActor* Actor);
    
};

