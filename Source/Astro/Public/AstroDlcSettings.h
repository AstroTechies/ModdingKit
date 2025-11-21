#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AstroDlcSettings.generated.h"

UCLASS(Blueprintable, Config=Game)
class UAstroDlcSettings : public UDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TArray<FString> GlitchwalkersId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TArray<FString> StarSeekerId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, GlobalConfig, meta=(AllowPrivateAccess=true))
    TArray<FString> MegatechId;
    
    UAstroDlcSettings();

};

