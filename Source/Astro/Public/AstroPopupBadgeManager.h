#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroPopupBadgeManager.generated.h"

class UPopupBadgeWidgetComponent;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UAstroPopupBadgeManager : public UActorComponent
{
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Export, Transient)
    TArray<UPopupBadgeWidgetComponent *> LivingAstroPopupBadges;

private:
    UPROPERTY(Transient)
    uint8 PopupBadgesDisabled : 1;

public:
    UAstroPopupBadgeManager();
};
