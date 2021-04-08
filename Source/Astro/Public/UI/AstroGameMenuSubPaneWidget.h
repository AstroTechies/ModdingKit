// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/AstroGameMenuSpatialWindow.h"
#include "AstroGameMenuSubPaneWidget.generated.h"

UCLASS(BlueprintType)
class ASTRO_API UAstroGameMenuSubPaneWidget : public UAstroGameMenuSpatialWindow
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bFullScreen;
};