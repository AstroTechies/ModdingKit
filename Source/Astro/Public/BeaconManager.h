#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BeaconManager.generated.h"

class AAstroCharacter;
class AAstroGameState;
class ABeaconBase;
class APlayController;
class ASolarBody;

UCLASS(Blueprintable)
class UBeaconManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABeaconBase*> ActiveBeacons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABeaconBase*> HiddenBeacons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ABeaconBase*> UpdateQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroGameState* GameStateCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayController* PlayControllerCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacterCache;
    
public:
    UBeaconManager();

private:
    UFUNCTION(BlueprintCallable)
    void OnLocalSolarBodyChanged(ASolarBody* newBody);
    
};

