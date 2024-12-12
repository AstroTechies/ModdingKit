#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
    AAdaptiveTickGroup(const FObjectInitializer& ObjectInitializer);

};

