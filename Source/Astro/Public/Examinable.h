#pragma once
#include "CoreMinimal.h"
#include "Crackable.h"
#include "Examinable.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UExaminable : public UCrackable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AutoDismissRange;
    
    UExaminable();
    UFUNCTION(BlueprintCallable)
    bool ValidateWithinExamineRange();
    
};

