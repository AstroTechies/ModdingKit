#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EAstroUIAudioEventKey.h"
#include "AstroUIAudioDatabase.generated.h"

UCLASS(Blueprintable, Blueprintable)
class UAstroUIAudioDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<EAstroUIAudioEventKey, FString> UIAudioEventMap;

    UAstroUIAudioDatabase();
};
