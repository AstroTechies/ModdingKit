#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
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

