#pragma once
#include "CoreMinimal.h"
#include "Activation.h"
#include "MultiActivation.generated.h"

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API UMultiActivation : public UActivation
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Transient)
    int32 m_activationCount;

public:
    UMultiActivation();
};
