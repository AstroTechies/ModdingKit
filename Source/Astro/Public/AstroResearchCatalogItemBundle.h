#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroResearchCatalogItemBundle.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroResearchCatalogItemBundle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TSubclassOf<UItemType>> ItemsInBundle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText LocBundleName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FString BundleIdentifier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool IsEnabled;
    
    ASTRO_API FAstroResearchCatalogItemBundle();
};

