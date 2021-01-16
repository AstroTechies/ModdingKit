// Fill out your copyright notice in the Description page of Project Settings.

#include "PlanetStatics.h"
#include "AstroPlanet.h"
#include "Engine/World.h"
#include "Engine.h"

AAstroPlanet* UPlanetStatics::GetPlanet(UPARAM(ref)AActor * actor, bool bBoundsCheck)
{
	return nullptr;
}

bool UPlanetStatics::IsTerrainReadyAtLocation(UObject* WorldContextObject, FVector location)
{
	return true;
}