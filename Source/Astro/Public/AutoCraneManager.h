#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AutoCraneOverlapTestRequest.h"
#include "AutoCraneState.h"
#include "AutoCraneManager.generated.h"

class AActor;
class AAstroCharacter;
class AAutoCrane;
class APlayController;
class ASolarBody;

UCLASS(Blueprintable)
class UAutoCraneManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAutoCraneState> CraneStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAutoCraneOverlapTestRequest> ShapeCastRequests;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AActor*> ProcessedActorCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayController* PlayControllerCache;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAstroCharacter* AstroCharacterCache;
    
public:
    UAutoCraneManager();
private:
    UFUNCTION(BlueprintCallable)
    void OnTransferItemSet(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnTransferItemReleased(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnTransferItemFullyEmplaced(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnTransferItemDestroyed(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnLocalSolarBodyChanged(ASolarBody* newBody);
    
    UFUNCTION(BlueprintCallable)
    void OnCraneReleasedFromSlot(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnCranePowerChanged(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnCranePlacedInSlot(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnCraneInputUse(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnClientTransferProgressChanged(AAutoCrane* Crane);
    
    UFUNCTION(BlueprintCallable)
    void OnClientCraneStateChanged(AAutoCrane* Crane);
    
};

