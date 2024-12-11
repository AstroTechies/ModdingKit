#pragma once
#include "CoreMinimal.h"
#include "Engine/GameEngine.h"
#include "AstroEngineCommon.h"
#include "AstroEngine.generated.h"

UCLASS(Blueprintable, NonTransient)
class UAstroEngine : public UGameEngine {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroEngineCommon m_engineCommon;
    
public:
    UAstroEngine();

};

