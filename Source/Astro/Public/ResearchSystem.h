#pragma once
#include "CoreMinimal.h"
#include "AstroDatumRef.h"
#include "AstroEntitySystem.h"
#include "ResearchSubjectComponent.h"
#include "Templates/SubclassOf.h"
#include "ResearchSystem.generated.h"

class AAstroGameState;
class APhysicalItem;
class APlayerController;
class UItemComponent;
class UItemType;
class UObject;

UCLASS(Blueprintable)
class ASTRO_API UResearchSystem : public UAstroEntitySystem {
    GENERATED_BODY()
public:
    UResearchSystem();

    UFUNCTION(BlueprintCallable)
    static void StartOrInterruptResearch(FAstroDatumRef ResearchEntityRef, FAstroDatumRef InstigatorEntityRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchSubjectSet(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchSubjectReleased(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchSubjectItemTypeChanged(UItemComponent* researchSubjectItemComponent, TSubclassOf<UItemType> NewItemType);
    
    UFUNCTION(BlueprintCallable)
    void OnResearchSubjectDestroyedInSlot(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemTypeUnlockedForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemTypeUnlocked(const APlayerController* PlayerController, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemTypeKnownForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsItemTypeHackedForGame(const AAstroGameState* GameState, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetResearchTimeProgressRatio(const FResearchSubjectComponent& ResearchSubject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetResearchSubjectTotals(const FResearchSubjectComponent& ResearchSubject, float& OutTotalPointsFromSubject, float& OutSubjectTotalResearchTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetResearchPointProgressRatio(const FResearchSubjectComponent& ResearchSubject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetCurrentResearchPointsPerMinute(const APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetCurrentResearchPointBalance(const APlayerController* PlayerController);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void AuthorityGrantResearchPoints(const UObject* WorldContextObject, int32 PointsToGrant);
    
};

