#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=RepMovement -FallbackName=RepMovement
#include "RepLinkedChassisMovement.h"
#include "RepWheeledChassisMovement.generated.h"

USTRUCT(BlueprintType)
struct FRepWheeledChassisMovement {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRepMovement Movement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRepLinkedChassisMovement> linkedMovement;
    
    ASTRO_API FRepWheeledChassisMovement();
};

