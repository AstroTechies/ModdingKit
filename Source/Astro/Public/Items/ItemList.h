// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/ItemType.h"
#include "Engine/DataAsset.h"
#include "ItemList.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ASTRO_API UItemList : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TSubclassOf<UItemType>> ItemTypes;
};
