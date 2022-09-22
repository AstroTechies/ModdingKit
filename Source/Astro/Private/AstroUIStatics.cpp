#include "AstroUIStatics.h"
#include "Templates/SubclassOf.h"

class UBorder;
class UImage;
class UObject;
class UWidget;
class UAstroUIStylingDatabase;
class UItemType;
class UAstroPopupBadgeDatabase;
class UWidgetAnimation;
class AActor;

FSlateBrush UAstroUIStatics::SlateBrushWithNewSlateColor(FSlateBrush SlateBrush, FSlateColor SlateColor) {
    return FSlateBrush{};
}

FSlateBrush UAstroUIStatics::SlateBrushWithNewColor(FSlateBrush SlateBrush, FLinearColor LinearColor) {
    return FSlateBrush{};
}

void UAstroUIStatics::SetImageBrushSlateColor(UImage* Image, FSlateColor BrushColor) {
}

void UAstroUIStatics::SetImageBrushSize(UImage* Image, FVector2D NewSize) {
}

void UAstroUIStatics::SetImageBrushImage(UImage* Image, UObject* ImageResource) {
}

void UAstroUIStatics::SetImageBrushColor(UImage* Image, FLinearColor BrushColor) {
}

void UAstroUIStatics::SetBorderBrushSlateColor(UBorder* Border, FSlateColor Color) {
}

void UAstroUIStatics::SetBorderBrushImage(UBorder* Border, UObject* ImageResource) {
}

void UAstroUIStatics::SetBorderBrushDrawAs(UBorder* Border, TEnumAsByte<ESlateBrushDrawType::Type> DrawAsType) {
}

void UAstroUIStatics::SetAllUserFocus(UWidget* WidgetToFocus) {
}

UAstroUIStylingDatabase* UAstroUIStatics::GetAstroUIStylingDatabase() {
    return NULL;
}

FString UAstroUIStatics::GetAstroUIAudioEvent(EAstroUIAudioEventKey AudioEventKey) {
    return TEXT("");
}

UAstroPopupBadgeDatabase* UAstroUIStatics::GetAstroPopupBadgeDatabase() {
    return NULL;
}

float UAstroUIStatics::GetAnimationDuration(const UWidgetAnimation* InAnimation) {
    return 0.0f;
}

void UAstroUIStatics::DisplayPopupBadgeForItemPing(AActor* OwningActor, TSubclassOf<UItemType> ItemType) {
}

void UAstroUIStatics::DisplayPopupBadge(AActor* OwningActor, const FAstroPopupBadgeAuthoringData& AuthoringData) {
}

void UAstroUIStatics::ClearAllUserFocus() {
}

UAstroUIStatics::UAstroUIStatics() {
}

