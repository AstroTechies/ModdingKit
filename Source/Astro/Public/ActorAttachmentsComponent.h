#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "AttachEnterExitSignalDelegate.h"
#include "AttachedActorSignalDelegate.h"
#include "AttachmentDefinition.h"
#include "AttachmentState.h"
#include "PerformAuxActionSignalDelegate.h"
#include "SetLandedDelegateDelegate.h"
#include "ActorAttachmentsComponent.generated.h"

class AActor;
class AAstroPlayerController;
class APlayController;
class APlayerController;
class UActorAttachmentsComponent;
class UAstroSaveCustomArchiveProxy;
class USceneComponent;
class UStorageChassisComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorAttachmentsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 MaxAttachedPlayerCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UsePlanetCameraUp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowFreeCam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DisableViewTargetChangeOnExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EntryInterpolationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EntryInterpolationEaseOutExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitInterpolationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitInterpolationEaseOutExponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DetachGroundedTrace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool CanEnter;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSetLandedDelegate OnSetLanded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttachEnterExitSignal OnEnterExit;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttachedActorSignal OnActorCompletedEntry;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAttachedActorSignal OnActorCompletedExit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttachmentDefinition> AttachmentDefinitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_Attachments, meta=(AllowPrivateAccess=true))
    TArray<FAttachmentState> AttachmentStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAttachmentState> OldAttachments;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformAuxActionSignal OnPerformAux1Action;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformAuxActionSignal OnPerformAux2Action;
    
protected:
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint32 ExitSuppressionCount;
    
public:
    UActorAttachmentsComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    AAstroPlayerController* TryGetFirstAttachedPlayer(bool bIgnoreExiting);
    
    UFUNCTION(BlueprintCallable)
    static bool TogglePlayerAttachedStorage(APlayerController* Controller, UStorageChassisComponent* storage, bool& Toggled, bool bImmediate, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    bool ToggleClickPlayerAttached(bool& Toggled);
    
    UFUNCTION(BlueprintCallable)
    bool ToggleAttached(AActor* Actor, bool& Toggled, bool setViewTarget, bool bImmediate);
    
private:
    UFUNCTION(BlueprintCallable)
    void SetupAttachedViewTargetsDelayed();
    
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void PushExitSuppression();
    
    UFUNCTION(BlueprintCallable)
    void PopExitSuppression();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Attachments();
    
    UFUNCTION(BlueprintCallable)
    void OnAttachedActorDestroyed(AActor* DestroyedActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasController(APlayController* Controller);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasClickPlayer();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasActor(AActor* Actor, int32& outIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetFirstAttachedActor(bool bIgnoreExiting);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetDetachTransform(int32 I) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetAttachTransform(int32 I) const;
    
    UFUNCTION(BlueprintCallable)
    void FinishExiting(int32 I);
    
    UFUNCTION(BlueprintCallable)
    void DetachAll(bool bImmediate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanExit() const;
    
    UFUNCTION(BlueprintCallable)
    static TArray<APlayController*> AttachedArrayPlayers(const TArray<UActorAttachmentsComponent*>& Attachments);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AttachedArrayHasPlayer(const TArray<UActorAttachmentsComponent*>& Attachments);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UActorAttachmentsComponent* AttachedArrayHasActor(const TArray<UActorAttachmentsComponent*>& Attachments, AActor* Actor, int32& outIndex);
    
    UFUNCTION(BlueprintCallable)
    static USceneComponent* AttachedArrayAvailable(const TArray<UActorAttachmentsComponent*>& Attachments, const FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UActorAttachmentsComponent* ActorActorAttachmentsComponent(AActor* Actor);
    
};

