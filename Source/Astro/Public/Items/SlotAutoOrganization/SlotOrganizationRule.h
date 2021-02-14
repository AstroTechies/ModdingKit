// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slots/SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "SlotOrganizationRule.generated.h"

UENUM(BlueprintType)
enum class EIndicatorTooltipType : uint8 {
	ResourceRequest = 0,
	CraftingOutputPreview = 1,
	NoTooltip = 2
};

/**
 * 
 */
UCLASS(EditInlineNew)
class ASTRO_API USlotOrganizationRule : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		void SetEnabled(bool enabled);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName RuleName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> ManagedSlots;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Priority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EIndicatorTooltipType IndicatorType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float UnwantedItemEjectionForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FSlotReference> ManagedSlotRefs;
};
