#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GateObjectReference.h"
#include "EGateObjectType.h"
#include "GateObjectControlNode.generated.h"

class UStaticMeshComponent;
class UTooltipComponent;
class UGateObjectIndicatorDefinition;

USTRUCT(BlueprintType)
struct FGateObjectControlNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FGateObjectReference GateObjectRef;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    EGateObjectType GateObjectType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    UPROPERTY()
    float RelativeOffsetSolarScalar;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector RelativeOffset;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* NodeMesh;
    
    UPROPERTY(Export)
    TArray<UStaticMeshComponent*> ChildMeshes;
    
    UPROPERTY(Export)
    UTooltipComponent* TooltipComponent;
    
    UPROPERTY()
    UGateObjectIndicatorDefinition* IndicatorDefinition;
    
    ASTRO_API FGateObjectControlNode();
};

