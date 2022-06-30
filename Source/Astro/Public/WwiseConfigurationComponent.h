#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WwiseConfigurationComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UWwiseConfigurationComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TArray<FString> RequiredAudioBankNames;

    UWwiseConfigurationComponent();
};
