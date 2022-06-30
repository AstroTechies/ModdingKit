#pragma once
#include "CoreMinimal.h"
#include "ETetherAttachmentType.generated.h"

UENUM()
enum class ETetherAttachmentType : uint8 {
    Chassis,
    Post,
    Vehicle,
    Character,
};

