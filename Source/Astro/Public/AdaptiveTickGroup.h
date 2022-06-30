#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickingObject.h"
#include "AdaptiveTickGroup.generated.h"

class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class AAdaptiveTickGroup : public AActor
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    TArray<AAstroCharacter *> m_characters;

    UPROPERTY(Transient)
    TArray<FTickingObject> m_mobileObjects;

    UPROPERTY(Transient)
    TArray<FTickingObject> m_staticObjects;

public:
    AAdaptiveTickGroup();
};
