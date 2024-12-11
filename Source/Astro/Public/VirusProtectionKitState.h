#pragma once
#include "CoreMinimal.h"
#include "VirusProtectionKitState.generated.h"

USTRUCT(BlueprintType)
struct FVirusProtectionKitState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsRootKitInstalled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsCounterhackKeySubmitted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 VirusProtectionLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 SubmittedStormDataCount;
    
    ASTRO_API FVirusProtectionKitState();
};

