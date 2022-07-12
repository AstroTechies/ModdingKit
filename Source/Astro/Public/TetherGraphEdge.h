#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FTetherGraphEdge {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* B;
    
public:
    ASTRO_API FTetherGraphEdge();
};

