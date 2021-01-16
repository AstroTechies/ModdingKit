// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EmoteTable.generated.h"

class UAstroEmoteDefinition;

UCLASS(BlueprintType)
class ASTRO_API UEmoteTable : public UDataAsset
{
	GENERATED_BODY()

public:

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAstroPlayMontageAction> DefaultEmoteActionType;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UAstroEmoteDefinition *> DefaultEmoteSet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSoftObjectPtr<UAstroEmoteDefinition>> Emotes;
};