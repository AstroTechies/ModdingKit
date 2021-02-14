// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemSlot.h"

// Sets default values
AItemSlot::AItemSlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("SlotClickableComponent"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void AItemSlot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}