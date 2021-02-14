// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlotReference.generated.h"

class USlotsComponent;

USTRUCT(BlueprintType)
struct ASTRO_API FSlotReference
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USlotsComponent* Component;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName SlotName;
};