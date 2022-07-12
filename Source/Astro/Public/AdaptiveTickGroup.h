#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "TickingObject.h"
#include "AdaptiveTickGroup.generated.h"

class AAstroCharacter;

UCLASS(Blueprintable)
class AAdaptiveTickGroup : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAstroCharacter*> m_characters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTickingObject> m_mobileObjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTickingObject> m_staticObjects;
    
public:
    AAdaptiveTickGroup();
};

