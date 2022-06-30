#pragma once
#include "CoreMinimal.h"
#include "InitialClientStateParams.generated.h"

USTRUCT(BlueprintType)
struct FInitialClientStateParams {
    GENERATED_BODY()
public:
    UPROPERTY()
    bool IsReturningPlayer;
    
    UPROPERTY()
    bool GameUsesTitleMenu;
    
    UPROPERTY()
    bool GameUsesIntroCinematic;
    
    UPROPERTY()
    bool IsHostDedicatedServer;
    
    UPROPERTY()
    bool IsJoiningCreativeModeGame;
    
    UPROPERTY()
    bool IsJoiningGameWithCreativeModeActive;
    
    UPROPERTY()
    FString BackendNetID;
    
    UPROPERTY()
    FString ActiveSaveName;
    
    ASTRO_API FInitialClientStateParams();
};

