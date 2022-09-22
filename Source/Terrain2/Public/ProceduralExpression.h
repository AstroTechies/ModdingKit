#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "ProceduralExpression.generated.h"

UCLASS(Abstract, Blueprintable)
class TERRAIN2_API UProceduralExpression : public UObject {
    GENERATED_BODY()
public:
    UProceduralExpression();
};

