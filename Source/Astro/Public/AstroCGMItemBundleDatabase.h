#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AstroResearchCatalogItemBundle.h"
#include "AstroCGMItemBundleDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroCGMItemBundleDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAstroResearchCatalogItemBundle> ItemBundles;
    
    UAstroCGMItemBundleDatabase();

};

