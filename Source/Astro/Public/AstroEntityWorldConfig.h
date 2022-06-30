#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "AstroEntityWorldConfig.generated.h"

class UAstroEntitySystem;
class UAstroEntityWorld;
class UAstroEntityComponentContainer;

UCLASS(Blueprintable, Blueprintable)
class UAstroEntityWorldConfig : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UAstroEntityWorld> EntityWorldType;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UAstroEntityComponentContainer>> EntityComponentTypes;

    UPROPERTY(EditDefaultsOnly)
    TArray<TSubclassOf<UAstroEntitySystem>> EntitySystemTypes;

    UAstroEntityWorldConfig();
};
