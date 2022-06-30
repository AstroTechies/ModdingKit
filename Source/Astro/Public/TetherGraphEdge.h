#pragma once
#include "CoreMinimal.h"
#include "TetherGraphEdge.generated.h"

class UTetherAttachComponent;

USTRUCT(BlueprintType)
struct FTetherGraphEdge {
    GENERATED_BODY()
public:
private:
    UPROPERTY(Export)
    UTetherAttachComponent* A;
    
    UPROPERTY(Export)
    UTetherAttachComponent* B;
    
public:
    ASTRO_API FTetherGraphEdge();
};

FORCEINLINE uint32 GetTypeHash(const FTetherGraphEdge& TetherGraphEdge) {
    return 0;
}