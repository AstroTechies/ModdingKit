#pragma once
#include "CoreMinimal.h"
#include "SlotReference.h"
#include "OnSpawnedActorDelegate.generated.h"

class UBiodomePlantComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSpawnedActor, FSlotReference, Slot, UBiodomePlantComponent*, plantSpawned);

