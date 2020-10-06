// Fill out your copyright notice in the Description page of Project Settings.

#include "SolarBody.h"


// Sets default values
ASolarBody::ASolarBody()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolarBody::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolarBody::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASolarBody::GetCenter()
{
	return FVector();
}

FVector ASolarBody::GetProxyCenter()
{
	return FVector();
}