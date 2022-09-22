#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
#include "AstroNotificationUnlockAuthoringData.h"
#include "AstroNotificationToastAuthoringData.h"
#include "AstroNotificationTagAuthoringData.h"
#include "AstroNotificationStatics.generated.h"

class AActor;
class UObject;
class UAstroNotificationDatabase;
class UItemType;
class USceneComponent;

UCLASS(Blueprintable)
class ASTRO_API UAstroNotificationStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroNotificationStatics();
    UFUNCTION()
    static void PresentUnlockNotification(UObject* WorldContextObject, const FAstroNotificationUnlockAuthoringData& AuthoringData);
    
    UFUNCTION()
    static void PresentToastNotification(UObject* WorldContextObject, const FAstroNotificationToastAuthoringData& AuthoringData, bool bPushToFrontOfQueue);
    
    UFUNCTION()
    static void PresentResearchPointGrantNotificationData(AActor* OwningActor, int32 ResearchPoints);
    
    UFUNCTION()
    static void PresentCatalogItemUnlockNotification(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static void ImmediatelyPresentNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference);
    
    UFUNCTION(BlueprintPure)
    static UAstroNotificationDatabase* GetAstroNotificationDatabase();
    
    UFUNCTION(BlueprintCallable)
    static void EnqueueNotificationWidget(AActor* OwningActor, const FAstroNotificationTagAuthoringData& AuthoringData, USceneComponent* OverrideAnchorReference, bool AllowDuplicateEnqueue);
    
    UFUNCTION(BlueprintCallable)
    static FAstroNotificationTagAuthoringData CreateNotificationTagDataForItemPing(UObject* WorldContextObject, TSubclassOf<UItemType> ItemType);
    
};

