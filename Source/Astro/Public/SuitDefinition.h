#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SuitDefinition.generated.h"

class UAnimMontage;
class USkeletalMesh;
class UAnimInstance;

USTRUCT(BlueprintType)
struct FSuitDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimationBlueprintType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimMontage> PointMontage;
    
    ASTRO_API FSuitDefinition();
};

