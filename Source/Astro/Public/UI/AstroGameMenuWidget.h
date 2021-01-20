// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AstroGameMenuStatics.h"
#include "UI/UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASTRO_API UAstroGameMenuWidget : public UUserWidgetBlueprintDesignable
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuOpenClose, EAstroGameMenuContext, Context);

	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnMenuOpenClose OnMenuOpened;
	UPROPERTY(EditAnywhere, BlueprintAssignable, BlueprintReadWrite)
		FOnMenuOpenClose OnMenuClosed;
};
