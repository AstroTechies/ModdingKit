#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=ESlateBrushDrawType -FallbackName=ESlateBrushDrawType
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateBrush -FallbackName=SlateBrush
//CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=SlateColor -FallbackName=SlateColor
#include "AstroPopupBadgeAuthoringData.h"
#include "EAstroUIAudioEventKey.h"
#include "Templates/SubclassOf.h"
#include "AstroUIStatics.generated.h"

class AActor;
class UAstroPopupBadgeDatabase;
class UAstroUIStylingDatabase;
class UBorder;
class UImage;
class UItemType;
class UWidget;
class UWidgetAnimation;

UCLASS(Blueprintable)
class UAstroUIStatics : public UObject {
    GENERATED_BODY()
public:
    UAstroUIStatics();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlateBrush SlateBrushWithNewSlateColor(FSlateBrush SlateBrush, FSlateColor SlateColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FSlateBrush SlateBrushWithNewColor(FSlateBrush SlateBrush, FLinearColor LinearColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushSlateColor(UImage* Image, FSlateColor BrushColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushSize(UImage* Image, FVector2D NewSize);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushImage(UImage* Image, UObject* ImageResource);
    
    UFUNCTION(BlueprintCallable)
    static void SetImageBrushColor(UImage* Image, FLinearColor BrushColor);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushSlateColor(UBorder* Border, FSlateColor Color);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushImage(UBorder* Border, UObject* ImageResource);
    
    UFUNCTION(BlueprintCallable)
    static void SetBorderBrushDrawAs(UBorder* Border, TEnumAsByte<ESlateBrushDrawType::Type> DrawAsType);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllUserFocus(UWidget* WidgetToFocus);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAstroUIStylingDatabase* GetAstroUIStylingDatabase();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetAstroUIAudioEvent(EAstroUIAudioEventKey AudioEventKey);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAstroPopupBadgeDatabase* GetAstroPopupBadgeDatabase();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    static float GetAnimationDuration(const UWidgetAnimation* InAnimation);
    
    UFUNCTION(BlueprintCallable)
    static void DisplayPopupBadgeForItemPing(AActor* OwningActor, TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable)
    static void DisplayPopupBadge(AActor* OwningActor, const FAstroPopupBadgeAuthoringData& AuthoringData);
    
    UFUNCTION(BlueprintCallable)
    static void ClearAllUserFocus();
    
};

