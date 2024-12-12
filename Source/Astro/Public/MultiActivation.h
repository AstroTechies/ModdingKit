#pragma once
#include "CoreMinimal.h"
#include "Activation.h"
#include "MultiActivation.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UMultiActivation : public UActivation {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 m_activationCount;
    
public:
    UMultiActivation();

};

