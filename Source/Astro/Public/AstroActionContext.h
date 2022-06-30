#pragma once
#include "CoreMinimal.h"
#include "AstroActionContext.generated.h"

class AActor;
class UAstroActionComponent;

USTRUCT(BlueprintType)
struct FAstroActionContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    AActor* Avatar;
    
    UPROPERTY(BlueprintReadWrite, Export, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    ASTRO_API FAstroActionContext();
};

