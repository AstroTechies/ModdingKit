// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemList.h"
#include "Items/SlotAutoOrganization/SlotOrganizationRule.h"
#include "WhitelistOrganizationRule.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, EditInlineNew)
class ASTRO_API UWhitelistOrganizationRule : public USlotOrganizationRule
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
		void SetShowIndicators(bool showIndicators);
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UItemList> ItemTypeWhitelist;
};