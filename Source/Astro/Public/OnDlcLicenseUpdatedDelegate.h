#pragma once
#include "CoreMinimal.h"
#include "EAstroDlcName.h"
#include "OnDlcLicenseUpdatedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDlcLicenseUpdated, EAstroDlcName, Dlc);

