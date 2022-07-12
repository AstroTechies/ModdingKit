#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Actor -FallbackName=Actor
#include "CapturableSnail.generated.h"

class UPlanetEffect;
class APhysicalItem;
class APlayController;
class AAstroCharacter;

UCLASS(Blueprintable)
class ASTRO_API ACapturableSnail : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPlanetEffect* PlanetEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SightDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FaceTargetSpeed;
    
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
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerExitedRelevance(AAstroCharacter* Player);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerEnteredRelevance(AAstroCharacter* Player);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnLeftAnyPlayerRelevance();
    
    UFUNCTION()
    void OnEffectRelevanceChanged(bool IsInRelevancy);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnCameOnscreen();
    
private:
    UFUNCTION()
    void OnActorOnscreenChanged(AActor* Actor, bool bIsOnscreen, APlayController* Player);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityStartCheckOnscreen();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityClearCheckOnscreen();
    
};

