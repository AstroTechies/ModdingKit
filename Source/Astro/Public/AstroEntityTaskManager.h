#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "AstroEntityTaskManager.generated.h"

class UAstroEntityWorld;
class UAstroDatumContainer;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UAstroEntityTaskManager : public UObject
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Transient)
    UAstroEntityWorld *EntityWorld;

    UPROPERTY(Transient)
    TArray<TSubclassOf<UAstroDatumContainer>> DependentDatumContainerTypes;

public:
    UAstroEntityTaskManager();
};
