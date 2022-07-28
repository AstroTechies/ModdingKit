// Fill out your copyright notice in the Description page of Project Settings.


#include "ProceduralPlacementFactory.h"
#include "ProceduralPlacement.h"

UProceduralPlacementFactory::UProceduralPlacementFactory() {
	bCreateNew = true;
	bEditAfterNew = true;
	
	SupportedClass = UProceduralPlacement::StaticClass();
}

UObject* UProceduralPlacementFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	UProceduralPlacement* Placement = NewObject<UProceduralPlacement>(InParent, InClass, InName, Flags);
	return Placement;
}
