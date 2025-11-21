#pragma once
#include "CoreMinimal.h"
#include "MegaModule.h"
#include "BiodomeModule.generated.h"

class ABiodome;

UCLASS(Blueprintable)
class ASTRO_API ABiodomeModule : public AMegaModule {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABiodome> Biodome;
    
public:
    ABiodomeModule(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnSlotted();
    
    UFUNCTION(BlueprintCallable)
    void OnReleased(bool NewOwner);
    
};

