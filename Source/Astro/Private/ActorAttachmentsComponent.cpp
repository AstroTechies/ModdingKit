// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorAttachmentsComponent.h"


bool UActorAttachmentsComponent::CanExit()
{
	return false;
}

void UActorAttachmentsComponent::PushExitSuppression()
{

}

void UActorAttachmentsComponent::PopExitSuppression()
{

}

bool UActorAttachmentsComponent::ToggleAttached(AActor* Actor, bool Toggled, bool setViewTarget, bool bImmediate)
{
	return false;
}

bool UActorAttachmentsComponent::ToggleClickPlayerAttached(bool Toggled)
{
	return false;
}

bool UActorAttachmentsComponent::TogglePlayerAttachedStorage(APlayerController* Controller, UStorageChassisComponent* storage, bool toggled, bool bImmediate, bool bForce)
{
	return false;
}

UActorAttachmentsComponent* UActorAttachmentsComponent::AttachedArrayHasActor(TArray<UActorAttachmentsComponent *> Attachments, AActor* Actor, int outIndex)
{
	return nullptr;
}

bool UActorAttachmentsComponent::AttachedArrayHasPlayer(TArray<UActorAttachmentsComponent *> Attachments)
{
	return false;
}

TArray<APlayController *> UActorAttachmentsComponent::AttachedArrayPlayers(TArray<UActorAttachmentsComponent *> Attachments)
{
	TArray<APlayController *> x;
	return x;
}

USceneComponent* UActorAttachmentsComponent::AttachedArrayAvailable(TArray<UActorAttachmentsComponent *> Attachments, FVector Location)
{
	return nullptr;
}

FTransform UActorAttachmentsComponent::GetAttachTransform(int i)
{
	return FTransform::FTransform();
}

FTransform UActorAttachmentsComponent::GetDetachTransform(int i)
{
	return FTransform::FTransform();
}

void UActorAttachmentsComponent::DetachAll(bool bImmediate)
{

}

AActor* UActorAttachmentsComponent::GetFirstAttachedActor(bool bIgnoreExiting)
{
	return nullptr;
}

bool UActorAttachmentsComponent::HasActor(AActor* Actor, int outIndex)
{
	return false;
}

bool UActorAttachmentsComponent::HasPlayer()
{
	return false;
}

bool UActorAttachmentsComponent::HasClickPlayer()
{
	return false;
}

bool UActorAttachmentsComponent::HasController(APlayController* Controller)
{
	return false;
}

UActorAttachmentsComponent* UActorAttachmentsComponent::ActorActorAttachmentsComponent(AActor* Actor)
{
	return nullptr;
}

void UActorAttachmentsComponent::FinishExiting(int i)
{

}

void UActorAttachmentsComponent::OnAttachedActorDestroyed(AActor* destroyedActor)
{

}

void UActorAttachmentsComponent::OnRep_Attachments()
{

}

/*void UActorAttachmentsComponent::SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy)
{

}*/