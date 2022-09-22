#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "OxygenChangeDelegateDelegate.h"
#include "LinearAttachPoint.h"
#include "SlotReference.h"
#include "CircularAttachPoint.h"
#include "ExplicitOxygenConnections.h"
#include "VampireAttachmentEntry.h"
#include "ETetherAttachmentType.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "TetherAttachComponent.generated.h"

class USceneComponent;
class UTetherNetwork;
class UTetherAttachComponent;
class UOxygenatorComponent;
class AActor;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<USceneComponent*> SingularAttachPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TetherAttachDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTetherNetwork* Network;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SaveGame, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTetherAttachComponent*> ConnectedTetherPosts;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVampireAttachmentEntry> VampireAttachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UOxygenatorComponent*> LinkedOxygenators;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UOxygenatorComponent* BuiltInOxygenator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TMap<UTetherAttachComponent*, FExplicitOxygenConnections> ExplicitOxygenConnections;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETetherAttachmentType TetherAttachmentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConnectToCharactersOnlyWithoutExternalOxygenator;
    
public:
    UTetherAttachComponent();
    UFUNCTION(BlueprintCallable)
    void UpdateExplicitNetwork();
    
    UFUNCTION()
    void TeardownLinkToOxygenator(UOxygenatorComponent* oxygenator);
    
    UFUNCTION(BlueprintCallable)
    void SetCanAttach(bool NewCanAttach, bool ForceUpdate, bool fromSave);
    
private:
    UFUNCTION()
    void OnOwnerMotionStateChanged();
    
public:
    UFUNCTION()
    void OnOwnerDestroy(AActor* Actor);
    
private:
    UFUNCTION()
    void OnBuiltInOxygenatorOxygenChanged(UOxygenatorComponent* oxygenator);
    
    UFUNCTION()
    void OnBuiltInOxygenatorDestroyed(UOxygenatorComponent* oxygenator);
    
public:
    UFUNCTION(BlueprintPure)
    ETetherAttachmentType GetTetherAttachmentType();
    
    UFUNCTION(BlueprintPure)
    float GetPowerFlowOnVampireConnections();
    
    UFUNCTION(BlueprintCallable)
    FVector GetAttachPoint(FSlotReference SlotRef, const FVector& InLocation, bool allowConnections);
    
    UFUNCTION(BlueprintPure)
    static UTetherAttachComponent* GetActorTetherAttachComponent(AActor* Actor);
    
    UFUNCTION(BlueprintPure)
    static UTetherAttachComponent* GetActorHierarchyTetherAttachComponent(AActor* Actor);
    
};

