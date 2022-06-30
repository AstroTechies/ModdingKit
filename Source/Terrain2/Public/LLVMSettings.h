#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "LLVMSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config = Game)
class TERRAIN2_API ULLVMSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Config, EditAnywhere)
    FFilePath ClangPath;

    UPROPERTY(Config, EditAnywhere)
    FFilePath LLVMLibPath;

    UPROPERTY(Config, EditAnywhere)
    FFilePath LLVMLinkPath;

    UPROPERTY(Config, EditAnywhere)
    FFilePath ClangPath10;

    UPROPERTY(Config, EditAnywhere)
    FFilePath LLVMLibPath10;

    UPROPERTY(Config, EditAnywhere)
    FFilePath LLVMLinkPath10;

    UPROPERTY(Config, EditAnywhere)
    TArray<FFilePath> CompiledLibraries;

public:
    ULLVMSettings();
};
