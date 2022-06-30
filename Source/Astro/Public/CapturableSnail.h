#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EEmoteType.h"
#include "CapturableSnail.generated.h"

class UPlanetEffect;
class APhysicalItem;
class APlayController;
class AAstroCharacter;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ACapturableSnail : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(Export, VisibleAnywhere)
    UPlanetEffect *PlanetEffect;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float SightDist;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float FaceTargetSpeed;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<AActor *> OverlappingPlayers;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    APhysicalItem *OwningCaptureTerrarium;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *CurrSightTarget;

public:
    ACapturableSnail();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOwningCaptureTerrarium(APhysicalItem *captureTerrarium);

    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerExitedRelevance(AAstroCharacter *Player);

    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerEnteredRelevance(AAstroCharacter *Player);

    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerEmotePlayed(EEmoteType EmoteType, APlayController *Player);

    UFUNCTION(BlueprintImplementableEvent)
    void OnLeftAnyPlayerRelevance();

    UFUNCTION(BlueprintImplementableEvent)
    void OnEmoteWheelOpenedOrClosed(bool bWheelOpen);

    UFUNCTION()
    void OnEffectRelevanceChanged(bool IsInRelevancy);

    UFUNCTION(BlueprintImplementableEvent)
    void OnCameOnscreen();

private:
    UFUNCTION()
    void OnActorOnscreenChanged(AActor *Actor, bool bIsOnscreen, APlayController *Player);

public:
    UFUNCTION(NetMulticast, Reliable, WithValidation)
    void MULTI_OnEmoteWheelOpenedOrClosed(bool bWheelOpen, APlayController *Player);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityStartCheckOnscreen();

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityClearCheckOnscreen();
};
