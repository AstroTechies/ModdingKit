// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LodAnchorState.generated.h"

UENUM(BlueprintType)
enum class ELodAnchorState : uint8 {
	Invalid = 255,
	NotAnchored = 0,
	Anchored = 1
};