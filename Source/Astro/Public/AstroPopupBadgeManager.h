#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroPopupBadgeManager.generated.h"

class UPopupBadgeWidgetComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UAstroPopupBadgeManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UPopupBadgeWidgetComponent*> LivingAstroPopupBadges;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 PopupBadgesDisabled: 1;
    
public:
    UAstroPopupBadgeManager();
};

