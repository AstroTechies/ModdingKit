#pragma once
#include "CoreMinimal.h"
#include "AutoCraneState.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AutoCraneOverlapTestRequest.h"
#include "AutoCraneManager.generated.h"

class ASolarBody;
class AActor;
class AAstroCharacter;
class APlayController;
class AAutoCrane;

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
    UFUNCTION()
    void OnTransferItemSet(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnTransferItemReleased(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnTransferItemFullyEmplaced(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnTransferItemDestroyed(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnLocalSolarBodyChanged(ASolarBody* newBody);
    
    UFUNCTION()
    void OnCraneReleasedFromSlot(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnCranePowerChanged(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnCranePlacedInSlot(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnCraneInputUse(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnClientTransferProgressChanged(AAutoCrane* Crane);
    
    UFUNCTION()
    void OnClientCraneStateChanged(AAutoCrane* Crane);
    
};

