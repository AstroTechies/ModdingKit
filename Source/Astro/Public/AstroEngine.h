#pragma once
#include "CoreMinimal.h"
#include "AstroEngineCommon.h"
#include "Engine/GameEngine.h"
#include "AstroEngine.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroEngine : public UGameEngine
{
    GENERATED_BODY()
public:
private:
    UPROPERTY()
    FAstroEngineCommon m_engineCommon;

public:
    UAstroEngine();
};
