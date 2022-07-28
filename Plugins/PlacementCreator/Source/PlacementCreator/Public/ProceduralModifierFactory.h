// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ProceduralModifierFactory.generated.h"

/**
 * 
 */
UCLASS()
class PLACEMENTCREATOR_API UProceduralModifierFactory : public UFactory
{
	GENERATED_BODY()
public:

	UProceduralModifierFactory();

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
