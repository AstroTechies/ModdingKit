#pragma once
#include "CoreMinimal.h"
#include "ProceduralExpression.h"
#include "ProceduralExpression_SmootherStep.generated.h"

UCLASS(Blueprintable, Blueprintable)
class TERRAIN2_API UProceduralExpression_SmootherStep : public UProceduralExpression
{
    GENERATED_BODY()
public:
    UProceduralExpression_SmootherStep();
};
