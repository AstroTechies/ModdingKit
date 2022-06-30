#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "EAstroEntityComponentSubobjectTickGroup.h"
#include "AstroEntityComponentSubobjectDefinition.generated.h"

class UAstroEntityComponentSubobject;

UCLASS(Blueprintable, BlueprintType, EditInlineNew)
class UAstroEntityComponentSubobjectDefinition : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName Name;

    UPROPERTY()
    TSubclassOf<UAstroEntityComponentSubobject> RuntimeSubobjectType;

    UPROPERTY()
    EAstroEntityComponentSubobjectTickGroup TickGroup;

    UAstroEntityComponentSubobjectDefinition();
};
