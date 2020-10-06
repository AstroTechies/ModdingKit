// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ControlSymbol.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UControlSymbol : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText AllCapsName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText TooltipSubtitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		// This seems to be completely unused, you can probably just ignore it
		UStaticMesh* IconMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString SoundEvent;
};
