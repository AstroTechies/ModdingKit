#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EAstroEntityComponentSubobjectTickGroup.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityComponentSubobjectDefinition.generated.h"

class UAstroEntityComponentSubobject;

UCLASS(Blueprintable, EditInlineNew)
class UAstroEntityComponentSubobjectDefinition : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroEntityComponentSubobject> RuntimeSubobjectType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAstroEntityComponentSubobjectTickGroup TickGroup;
    
    UAstroEntityComponentSubobjectDefinition();

};

