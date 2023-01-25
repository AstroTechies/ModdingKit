#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HUD -FallbackName=HUD
#include "GameFramework/HUD.h"
#include "EAstroGameMenuTutoriaSlideCardKey.h"
#include "EAstroGameMenuTutorialSlideDeckKey.h"
#include "Templates/SubclassOf.h"
#include "AstroHUD.generated.h"

class UAstroStoreMenuWidget;
class UAstropediaCarouselWidget;
class UPlayWidget;
class UReconnectWidget;
class USelectionWheelWidget;
class UTexture2DDynamic;
class UUserWidget;

UCLASS(Blueprintable, NonTransient)
class ASTRO_API AAstroHUD : public AHUD {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPlayWidget> PlayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> CreativeDroneOverlayClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstropediaCarouselWidget> AstropediaWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UReconnectWidget> ReconnectWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USelectionWheelWidget> ActionWheelWidgetClass;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPlayWidget* PlayWidgetInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* CreativeDroneOverlayInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UReconnectWidget* ReconnectWidgetInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MOTDBackgroundCDNKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2DDynamic* MOTDBackgroundTexture;
    
    AAstroHUD();
    UFUNCTION(BlueprintCallable)
    bool IsStoreActive();
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandlePlayerDeathBegins();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnCreativeShowCreativeDroneUIChanged(bool ShowUI);
    
public:
    UFUNCTION(BlueprintCallable)
    void DestroyStoreWidget();
    
    UFUNCTION(BlueprintCallable)
    void CreateStoreWidget();
    
    UFUNCTION(BlueprintCallable)
    bool CreateReconnectWidget();
    
    UFUNCTION(BlueprintCallable)
    UAstropediaCarouselWidget* CreateAstropediaWidget(EAstroGameMenuTutorialSlideDeckKey slideDeck, EAstroGameMenuTutoriaSlideCardKey slideCard);
    
};

