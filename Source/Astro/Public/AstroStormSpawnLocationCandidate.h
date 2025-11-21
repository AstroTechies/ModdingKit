#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Templates/SubclassOf.h"
#include "AstroStormSpawnLocationCandidate.generated.h"

class AAstroStorm;

UCLASS(Blueprintable)
class ASTRO_API AAstroStormSpawnLocationCandidate : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> StormClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    AAstroStorm* ActiveStorm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 ActiveStormID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FixedStormID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsBossStorm;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsRegistered;
    
    AAstroStormSpawnLocationCandidate(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    AAstroStorm* SpawnStorm(int32 StormID, int32 StateIndex);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool NewIsEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGlitchWalkersFinalEncounterStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGlitchWalkersFinalEncounterReset();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnGlitchWalkersFinalEncounterCompleted();
    
    UFUNCTION(BlueprintCallable)
    void Destroyed();
    
    UFUNCTION(BlueprintCallable)
    int32 ClearStorm();
    
    UFUNCTION(BlueprintCallable)
    void BeginPlay();
    
};

