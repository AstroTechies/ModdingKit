#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ProceduralExpression.generated.h"

UCLASS(Abstract, Blueprintable)
class TERRAIN2_API UProceduralExpression : public UObject {
    GENERATED_BODY()
public:
    UProceduralExpression();

};

