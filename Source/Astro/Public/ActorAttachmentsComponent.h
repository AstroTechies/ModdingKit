#pragma once
#include "CoreMinimal.h"
#include "SetLandedDelegateDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "AttachedActorSignalDelegate.h"
#include "AttachmentState.h"
#include "AttachEnterExitSignalDelegate.h"
#include "AttachmentDefinition.h"
#include "PerformAuxActionSignalDelegate.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
#include "ActorAttachmentsComponent.generated.h"

class AActor;
class APlayerController;
class UStorageChassisComponent;
class UAstroSaveCustomArchiveProxy;
class APlayController;
class UActorAttachmentsComponent;
class USceneComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorAttachmentsComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
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
    UPROPERTY(EditAnywhere, SaveGame)
    uint32 ExitSuppressionCount;
    
public:
    UActorAttachmentsComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    static bool TogglePlayerAttachedStorage(APlayerController* Controller, UStorageChassisComponent* storage, bool& Toggled, bool bImmediate, bool bForce);
    
    UFUNCTION(BlueprintCallable)
    bool ToggleClickPlayerAttached(bool& Toggled);
    
    UFUNCTION(BlueprintCallable)
    bool ToggleAttached(AActor* Actor, bool& Toggled, bool setViewTarget, bool bImmediate);
    
private:
    UFUNCTION()
    void SetupAttachedViewTargetsDelayed();
    
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable)
    void PushExitSuppression();
    
    UFUNCTION(BlueprintCallable)
    void PopExitSuppression();
    
    UFUNCTION()
    void OnRep_Attachments();
    
    UFUNCTION()
    void OnAttachedActorDestroyed(AActor* DestroyedActor);
    
    UFUNCTION(BlueprintPure)
    bool HasPlayer();
    
    UFUNCTION(BlueprintPure)
    bool HasController(APlayController* Controller);
    
    UFUNCTION(BlueprintPure)
    bool HasClickPlayer();
    
    UFUNCTION(BlueprintPure)
    bool HasActor(AActor* Actor, int32& outIndex);
    
    UFUNCTION(BlueprintPure)
    AActor* GetFirstAttachedActor(bool bIgnoreExiting);
    
    UFUNCTION(BlueprintPure)
    FTransform GetDetachTransform(int32 I) const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetAttachTransform(int32 I) const;
    
    UFUNCTION()
    void FinishExiting(int32 I);
    
    UFUNCTION(BlueprintCallable)
    void DetachAll(bool bImmediate);
    
    UFUNCTION(BlueprintPure)
    bool CanExit() const;
    
    UFUNCTION(BlueprintCallable)
    static TArray<APlayController*> AttachedArrayPlayers(const TArray<UActorAttachmentsComponent*>& Attachments);
    
    UFUNCTION(BlueprintPure)
    static bool AttachedArrayHasPlayer(const TArray<UActorAttachmentsComponent*>& Attachments);
    
    UFUNCTION(BlueprintPure)
    static UActorAttachmentsComponent* AttachedArrayHasActor(const TArray<UActorAttachmentsComponent*>& Attachments, AActor* Actor, int32& outIndex);
    
    UFUNCTION(BlueprintCallable)
    static USceneComponent* AttachedArrayAvailable(const TArray<UActorAttachmentsComponent*>& Attachments, const FVector& Location);
    
    UFUNCTION(BlueprintPure)
    static UActorAttachmentsComponent* ActorActorAttachmentsComponent(AActor* Actor);
    
};

