// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StorageChassisComponent.h"
#include "ActorAttachmentsComponent.generated.h"

UCLASS(BlueprintType)
class ASTRO_API UActorAttachmentsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		bool CanExit();
	UFUNCTION(BlueprintCallable)
		void PushExitSuppression();
	UFUNCTION(BlueprintCallable)
		void PopExitSuppression();
	UFUNCTION(BlueprintCallable)
		bool ToggleAttached(AActor* Actor, bool Toggled, bool setViewTarget, bool bImmediate);
	UFUNCTION(BlueprintCallable)
		bool ToggleClickPlayerAttached(bool Toggled);
	UFUNCTION(BlueprintCallable)
		bool TogglePlayerAttachedStorage(APlayerController* Controller, UStorageChassisComponent* storage, bool toggled, bool bImmediate, bool bForce);
	UFUNCTION(BlueprintCallable)
		UActorAttachmentsComponent* AttachedArrayHasActor(TArray<UActorAttachmentsComponent *> Attachments, AActor* Actor, int outIndex);
	UFUNCTION(BlueprintCallable)
		bool AttachedArrayHasPlayer(TArray<UActorAttachmentsComponent *> Attachments);
	UFUNCTION(BlueprintCallable)
		TArray<APlayController *> AttachedArrayPlayers(TArray<UActorAttachmentsComponent *> Attachments);
	UFUNCTION(BlueprintCallable)
		USceneComponent* AttachedArrayAvailable(TArray<UActorAttachmentsComponent *> Attachments, FVector Location);
	UFUNCTION(BlueprintCallable)
		FTransform GetAttachTransform(int i);
	UFUNCTION(BlueprintCallable)
		FTransform GetDetachTransform(int i);
	UFUNCTION(BlueprintCallable)
		void DetachAll(bool bImmediate);
	UFUNCTION(BlueprintCallable)
		AActor* GetFirstAttachedActor(bool bIgnoreExiting);
	UFUNCTION(BlueprintCallable)
		bool HasActor(AActor* Actor, int outIndex);
	UFUNCTION(BlueprintCallable)
		bool HasPlayer();
	UFUNCTION(BlueprintCallable)
		bool HasClickPlayer();
	UFUNCTION(BlueprintCallable)
		bool HasController(APlayController* Controller);
	UFUNCTION(BlueprintCallable)
		UActorAttachmentsComponent* ActorActorAttachmentsComponent(AActor* Actor);
	UFUNCTION(BlueprintCallable)
		void FinishExiting(int i);
	UFUNCTION(BlueprintCallable)
		void OnAttachedActorDestroyed(AActor* destroyedActor);
	UFUNCTION(BlueprintCallable)
		void OnRep_Attachments();
	/*UFUNCTION(BlueprintCallable)
		void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 MaxAttachedPlayerCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool UsePlanetCameraUp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool AllowFreeCam;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool DisableViewTargetChangeOnExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EntryInterpolationTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float EntryInterpolationEaseOutExponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExitInterpolationTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ExitInterpolationEaseOutExponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DetachGroundedTrace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanEnter;
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FSetLandedDelegate OnSetLanded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAttachEnterExitSignal OnEnterExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAttachedActorSignal OnActorCompletedEntry;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAttachedActorSignal OnActorCompletedExit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAttachmentDefinition> AttachmentDefinitions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAttachmentState> AttachmentStates;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FAttachmentState> OldAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPerformAuxActionSignal OnPerformAux1Action;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FPerformAuxActionSignal OnPerformAux2Action;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint ExitSuppressionCount;*/
};