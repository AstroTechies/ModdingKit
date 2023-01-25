#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroNotificationTagAuthoringData.h"
#include "AstroNotificationToastAuthoringData.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "Templates/SubclassOf.h"
#include "AstroNotificationStatics.generated.h"

class AActor;
class UAstroNotificationDatabase;
class UItemType;
class UObject;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroNotificationStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroNotificationStatics();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetShouldRetainBiomeToastNotification(UObject* WorldContextObject, bool bShouldRetain);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PresentUnlockNotification(UObject* WorldContextObject, const FAstroNotificationUnlockAuthoringData& AuthoringData);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PresentToastNotification(UObject* WorldContextObject, const FAstroNotificationToastAuthoringData& AuthoringData, bool bPushToFrontOfQueue);
    
    UFUNCTION(BlueprintCallable)
    static void PresentResearchPointGrantNotificationData(AActor* OwningActor, int32 ResearchPoints);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PresentCatalogItemUnlockNotification(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PresentBiomeToastNotification(UObject* WorldContextObject, const FAstroNotificationToastAuthoringData& AuthoringData);
    
    UFUNCTION(BlueprintCallable)
    static void ImmediatelyPresentNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAstroNotificationDatabase* GetAstroNotificationDatabase();
    
    UFUNCTION(BlueprintCallable)
    static void EnqueueNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference, bool AllowDuplicateEnqueue);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FAstroNotificationTagAuthoringData CreateNotificationTagDataForItemPing(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType);
    
};

