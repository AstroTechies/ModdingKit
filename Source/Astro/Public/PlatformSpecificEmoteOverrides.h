#pragma once
#include "CoreMinimal.h"
#include "PlatformSpecificEmoteOverrides.generated.h"

class UAnimMontage;
class UAstroEmoteDefinition;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct FPlatformSpecificEmoteOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAstroEmoteDefinition* Emote;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<USkeletalMesh>, TSoftObjectPtr<UAnimMontage>> SuitSpecificMontages;
    
    ASTRO_API FPlatformSpecificEmoteOverrides();
};

