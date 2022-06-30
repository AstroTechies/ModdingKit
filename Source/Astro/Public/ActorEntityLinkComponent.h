#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroEntityDefinition.h"
#include "AstroDatumRef.h"
#include "ActorEntityLinkComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UActorEntityLinkComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    FAstroEntityDefinition EntityDefinition;

protected:
    UPROPERTY(SaveGame)
    FAstroDatumRef EntityRef;

public:
    UActorEntityLinkComponent();
    UFUNCTION(BlueprintPure)
    bool IsSpawnedFromEntity() const;

    UFUNCTION(BlueprintPure)
    FAstroDatumRef GetEntityDatumRef(bool &bOutSuccess) const;
};
