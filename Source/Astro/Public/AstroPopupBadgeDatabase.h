#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "UObject/NoExportTypes.h"
#include "AstroPopupBadgeAuthoringData.h"
#include "AstroPopupBadgeDatabase.generated.h"

class UAstroPopupBadgeWidget;
class UCurveFloat;

UCLASS(Blueprintable, BlueprintType)
class UAstroPopupBadgeDatabase : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DefaultPopupBadgeColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor DefaultPopupBadgeStrokeColor;

    UPROPERTY(EditAnywhere)
    UCurveFloat *PopupBadgeDriftAnimationCurve;

    UPROPERTY(EditAnywhere)
    UCurveFloat *PopupBadgeFadeAnimationCurve;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UAstroPopupBadgeWidget> AstroPopupBadgeWidgetClass;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroPopupBadgeAuthoringData PowerPingCharge;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroPopupBadgeAuthoringData PowerPingDischarge;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroPopupBadgeAuthoringData Oxygen50;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    FAstroPopupBadgeAuthoringData Oxygen25;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float PowerPingRange;

    UAstroPopupBadgeDatabase();
};
