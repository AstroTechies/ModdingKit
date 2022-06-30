#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BaseEditorTool.generated.h"

UCLASS(Blueprintable, Abstract)
class ASTRO_API UBaseEditorTool : public UObject
{
    GENERATED_BODY()
public:
    UBaseEditorTool();
};
