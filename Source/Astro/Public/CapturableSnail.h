#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CapturableSnail.generated.h"

class AAstroCharacter;
class APhysicalItem;
class APlayController;
class UPlanetEffect;

UCLASS(Blueprintable)
class ASTRO_API ACapturableSnail : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SightDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FaceTargetSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bPerformOnscreenChecks: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OverlappingPlayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* OwningCaptureTerrarium;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* CurrSightTarget;
    
public:
    ACapturableSnail();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOwningCaptureTerrarium(APhysicalItem* captureTerrarium);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerExitedRelevance(AAstroCharacter* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayerEnteredRelevance(AAstroCharacter* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeftAnyPlayerRelevance();
    
    UFUNCTION(BlueprintCallable)
    void OnEffectRelevanceChanged(bool IsInRelevancy);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCameOnscreen();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnActorOnscreenChanged(AActor* Actor, bool bIsOnscreen, APlayController* Player);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityStartCheckOnscreen();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityClearCheckOnscreen();
    
};

