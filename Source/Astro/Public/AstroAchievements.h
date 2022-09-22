#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EAstroAchievementKeys.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroAchievements.generated.h"

class UObject;
class APlayerController;
class UItemType;

UCLASS(Blueprintable)
class ASTRO_API UAstroAchievements : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroAchievements();
    UFUNCTION(BlueprintCallable)
    static void IncrementAchievementProgressForAllPlayers(EAstroAchievementKeys Achievement, int32 AddedProgress, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementAchievementProgress(EAstroAchievementKeys Achievement, int32 AddedProgress, APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementAchievementFloatProgressForAllPlayers(EAstroAchievementKeys Achievement, float AddedProgress, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void IncrementAchievementFloatProgress(EAstroAchievementKeys Achievement, float AddedProgress, APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    static void AwardAchievementForAllPlayers(EAstroAchievementKeys Achievement, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void AwardAchievement(EAstroAchievementKeys Achievement, APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    static void AddAchievementCollectionItemForAllPlayers(EAstroAchievementKeys Achievement, TSubclassOf<UItemType> Item, UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void AddAchievementCollectionItem(EAstroAchievementKeys Achievement, TSubclassOf<UItemType> Item, APlayerController* Player);
    
};

