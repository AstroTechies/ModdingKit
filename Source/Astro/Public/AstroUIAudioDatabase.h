#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroUIAudioEventKey.h"
#include "AstroUIAudioDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroUIAudioDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroUIAudioEventKey, FString> UIAudioEventMap;
    
    UAstroUIAudioDatabase();

};

