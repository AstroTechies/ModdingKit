#pragma once
#include "CoreMinimal.h"
#include "PrimRoundedBox.generated.h"

USTRUCT()
struct FPrimRoundedBox {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float X;
    
    UPROPERTY(EditAnywhere)
    float Y;
    
    UPROPERTY(EditAnywhere)
    float Z;
    
    UPROPERTY(EditAnywhere)
    float R;
    
    TERRAIN2_API FPrimRoundedBox();
};

