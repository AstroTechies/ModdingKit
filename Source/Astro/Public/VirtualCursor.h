#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VirtualCursor.generated.h"

class UVirtualCursorWidget;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UVirtualCursor : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export)
    UVirtualCursorWidget *CursorWidget;

public:
    UVirtualCursor();
};
