#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=GameEngine -FallbackName=GameEngine
#include "AstroEngineCommon.h"
#include "Engine/GameEngine.h"
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

