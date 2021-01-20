// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/AstroGameMenuWidget.h"
#include "UObject/NoExportTypes.h"
#include "AstroGameSingleton.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroGameSingleton : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
		static UAstroGameSingleton* GetAstroGameSingleton();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAstroGameMenuWidget> GameMenu;
};
