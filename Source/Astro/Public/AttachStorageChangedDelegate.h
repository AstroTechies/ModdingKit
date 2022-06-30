#pragma once
#include "CoreMinimal.h"
#include "AttachStorageChangedDelegate.generated.h"

class UStorageChassisComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachStorageChanged, UStorageChassisComponent*, attachStorage);

