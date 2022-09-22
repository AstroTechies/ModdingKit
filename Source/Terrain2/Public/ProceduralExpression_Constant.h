#pragma once
#include "CoreMinimal.h"
#include "ProceduralExpression.h"
#include "ProceduralExpression_Constant.generated.h"

UCLASS(Blueprintable)
class TERRAIN2_API UProceduralExpression_Constant : public UProceduralExpression {
    GENERATED_BODY()
public:
    UProceduralExpression_Constant();
};

