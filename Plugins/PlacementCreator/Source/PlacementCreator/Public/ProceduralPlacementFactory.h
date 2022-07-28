// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ProceduralPlacementFactory.generated.h"

/**
 *
 */
UCLASS()
class PLACEMENTCREATOR_API UProceduralPlacementFactory : public UFactory
{
	GENERATED_BODY()

public:
	UProceduralPlacementFactory();

	virtual UObject *FactoryCreateNew(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn) override;
};
