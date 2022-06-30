#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/HUD.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "AstroHUD.generated.h"

class UAstropediaCarouselWidget;
class UUserWidget;
class UTexture2DDynamic;
class UPlayWidget;
class UReconnectWidget;
class USelectionWheelWidget;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AAstroHUD : public AHUD
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UPlayWidget> PlayWidget;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UUserWidget> CreativeDroneOverlayClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UAstropediaCarouselWidget> AstropediaWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UReconnectWidget> ReconnectWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<USelectionWheelWidget> EmoteWheelWidgetClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<USelectionWheelWidget> ActionWheelWidgetClass;

public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UPlayWidget *PlayWidgetInstance;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UUserWidget *CreativeDroneOverlayInstance;

    UPROPERTY(Export)
    UReconnectWidget *ReconnectWidgetInstance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString MOTDBackgroundCDNKey;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2DDynamic *MOTDBackgroundTexture;

    AAstroHUD();
    UFUNCTION(BlueprintCallable)
    bool IsStoreActive();

protected:
    UFUNCTION()
    void HandlePlayerDeathBegins();

    UFUNCTION()
    void HandleOnCreativeShowCreativeDroneUIChanged(bool ShowUI);

public:
    UFUNCTION(BlueprintCallable)
    void DestroyStoreWidget();

    UFUNCTION(BlueprintCallable)
    void CreateStoreWidget();

    UFUNCTION(BlueprintCallable)
    bool CreateReconnectWidget();

    UFUNCTION(BlueprintCallable)
    UAstropediaCarouselWidget *CreateAstropediaWidget(EAstroGameMenuTutorialSlideDeckKey slideDeck, EAstroGameMenuTutoriaSlideCardKey slideCard);
};
