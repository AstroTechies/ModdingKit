#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OnThemeActiveStatusChangedDelegate.h"
#include "AstroThemeNotificationComponent.generated.h"

class AActor;

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
    UAstroThemeNotificationComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void ValidateThemesStatus();
    
    UFUNCTION(BlueprintCallable)
    void OnThemeStatusChanged();
    
    UFUNCTION(BlueprintCallable)
    void CloneToActor(AActor* Actor);
    
};

