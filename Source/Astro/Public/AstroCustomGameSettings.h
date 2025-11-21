#pragma once
#include "CoreMinimal.h"
//#include "FAstroCGMLibraryConfigEntryType.h"
#include "CustomGameModifierCollection.h"
#include "AstroCustomGlitchWalkerSettings.h"
#include "AstroCustomMultiToolSettings.h"
#include "AstroCustomOxygenSettings.h"
#include "AstroCustomPowerSettings.h"
#include "AstroCustomResearchSettings.h"
#include "AstroResearchCatalogSettings.h"
#include "AstroRespawnTokenSettings.h"
#include "AstroStartingItemSettings.h"
#include "EPlanetIdentifier.h"
#include "StartingItemSlotData.h"
#include "AstroCustomGameSettings.generated.h"

USTRUCT(BlueprintType)
struct FAstroCustomGameSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 FormatVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString LocalConfigName;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
//    FAstroCGMLibraryConfigEntryType ConfigEntryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool SkipDropPodLaunchSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool NoStartingShelter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    EPlanetIdentifier StartingPlanetId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString StartingBiome;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FCustomGameModifierCollection ModifierCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroStartingItemSettings StartingItemSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FStartingItemSlotData> StartingItemSlotData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroRespawnTokenSettings RespawnTokenSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomResearchSettings ResearchSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroResearchCatalogSettings ResearchCatalogSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomPowerSettings PowerSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomOxygenSettings OxygenSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomMultiToolSettings MultiToolSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsGlitchWalkersConfiguration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroCustomGlitchWalkerSettings GlitchWalkerSettings;
    
    ASTRO_API FAstroCustomGameSettings();
};

