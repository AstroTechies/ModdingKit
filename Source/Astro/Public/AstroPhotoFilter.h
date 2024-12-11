#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ECharacterCustomizationVisibility.h"
#include "Templates/SubclassOf.h"
#include "AstroPhotoFilter.generated.h"

class UUserWidget;

UCLASS(Blueprintable)
class ASTRO_API UAstroPhotoFilter : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DisplayName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECharacterCustomizationVisibility DisplayVisibility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> FilterWidget;
    
    UAstroPhotoFilter();

};

