#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VirtualCursor.generated.h"

class UVirtualCursorWidget;

UCLASS(Blueprintable)
class ASTRO_API UVirtualCursor : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVirtualCursorWidget* CursorWidget;
    
public:
    UVirtualCursor();

};

