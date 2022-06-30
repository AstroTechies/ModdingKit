#pragma once
#include "CoreMinimal.h"
#include "PrimBox.generated.h"

USTRUCT()
struct FPrimBox {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    float X;
    
    UPROPERTY(EditAnywhere)
    float Y;
    
    UPROPERTY(EditAnywhere)
    float Z;
    
    TERRAIN2_API FPrimBox();
};

