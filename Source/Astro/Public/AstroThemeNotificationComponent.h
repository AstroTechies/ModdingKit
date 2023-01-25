#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnThemeActiveStatusChangedDelegate.h"
#include "AstroThemeNotificationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroThemeNotificationComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnThemeActiveStatusChanged ThemeOfInterestActiveStatusChanged;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> ThemesOfInterest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 OnlyDestroyBurried: 1;
    
public:
    UAstroThemeNotificationComponent();
    UFUNCTION(BlueprintCallable)
    void OnThemeStatusChanged();
    
};

