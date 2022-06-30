#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroDatumRef.h"
#include "AstroEntityComponentSubobject.generated.h"

class UAstroEntityComponentSubobjectDefinition;

UCLASS(Blueprintable, BlueprintType)
class UAstroEntityComponentSubobject : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, meta = (AllowPrivateAccess = true))
    FAstroDatumRef OwnerComponentRef;

    UPROPERTY(SaveGame)
    FName DefinitionName;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UAstroEntityComponentSubobjectDefinition *Definition;

    UAstroEntityComponentSubobject();
};
