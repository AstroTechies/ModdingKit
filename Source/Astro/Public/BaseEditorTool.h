#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "BaseEditorTool.generated.h"

UCLASS(Abstract, Blueprintable)
class ASTRO_API UBaseEditorTool : public UObject {
    GENERATED_BODY()
public:
    UBaseEditorTool();
};

