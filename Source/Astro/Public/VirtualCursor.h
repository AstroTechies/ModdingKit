#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "VirtualCursor.generated.h"

class UVirtualCursorWidget;

UCLASS(Blueprintable)
class ASTRO_API UVirtualCursor : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UVirtualCursorWidget* CursorWidget;
    
public:
    UVirtualCursor();
};

