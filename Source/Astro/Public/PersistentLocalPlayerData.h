#pragma once
#include "CoreMinimal.h"
//#include "AstroPlayFabClientData.h"
//#include "FAstroCGMLibraryConfigEntryType.h"
#include "UObject/Object.h"
#include "AstroCustomGameConfigurationStore.h"
#include "AstroCustomGameSettings.h"
#include "SignalDelegate.h"
#include "PersistentLocalPlayerData.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UPersistentLocalPlayerData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSignal OnDirtied;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasCompletedTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasSkippedTutorial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bHasSeenIntroCutscene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool bIsMultiplayerDisabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 LastUpdateCutsceneVersionSeen;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
//    FAstroPlayFabClientData OfflinePlayFabClientData;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<uint32> EarnedItemDrivePhysicalRewardHashes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FAstroCustomGameSettings> LocalCGMConfigs;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
//    TMap<FAstroCGMLibraryConfigEntryType, FAstroCustomGameConfigurationStore> CustomGameConfigurationLocalStorage;
    
public:
    UPersistentLocalPlayerData();

    UFUNCTION(BlueprintCallable)
    void NotifySkippedTutorial();
    
    UFUNCTION(BlueprintCallable)
    void NotifySeenIntroCutscene(bool wasUpdateCinematic);
    
    UFUNCTION(BlueprintCallable)
    void NotifyCompletedTutorial();
    
};

