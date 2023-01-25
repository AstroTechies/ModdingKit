#pragma once
#include "CoreMinimal.h"
#include "AstroActionContext.generated.h"

class AActor;
class UAstroActionComponent;

USTRUCT(BlueprintType)
struct FAstroActionContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Avatar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAstroActionComponent* ActionComponent;
    
    ASTRO_API FAstroActionContext();
};

