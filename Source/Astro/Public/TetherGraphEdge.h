#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FTetherGraphEdge {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* A;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTetherAttachComponent* B;
    
public:
    ASTRO_API FTetherGraphEdge();
};
FORCEINLINE uint32 GetTypeHash(const FTetherGraphEdge) { return 0; }

