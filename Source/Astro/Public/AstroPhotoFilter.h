#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DataAsset.h"
#include "AstroPhotoFilter.generated.h"

class UUserWidget;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UAstroPhotoFilter : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FText DisplayName;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> FilterWidget;

    UAstroPhotoFilter();
};
