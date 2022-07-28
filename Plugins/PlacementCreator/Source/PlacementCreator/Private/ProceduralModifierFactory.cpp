// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralModifierFactory.h"
#include "ProceduralModifier.h"

UProceduralModifierFactory::UProceduralModifierFactory()
{
	bCreateNew = true;
	bEditAfterNew = true;

	SupportedClass = UProceduralModifier::StaticClass();
}

UObject *UProceduralModifierFactory::FactoryCreateNew(UClass *InClass, UObject *InParent, FName InName, EObjectFlags Flags, UObject *Context, FFeedbackContext *Warn)
{
	UProceduralModifier *Modifier = NewObject<UProceduralModifier>(InParent, InClass, InName, Flags);
	return Modifier;
}