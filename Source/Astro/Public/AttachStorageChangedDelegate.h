#pragma once
#include "CoreMinimal.h"
#include "AttachStorageChangedDelegate.generated.h"

class UStorageChassisComponent;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachStorageChanged, UStorageChassisComponent*, attachStorage);

