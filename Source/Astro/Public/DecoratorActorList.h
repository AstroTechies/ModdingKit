#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorSpecifier.h"
#include "DecoratorActorList.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UDecoratorActorList : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TArray<FActorSpecifier> Actors;

    UDecoratorActorList();
};
