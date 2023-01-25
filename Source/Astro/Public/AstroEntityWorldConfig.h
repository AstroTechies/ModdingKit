#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "Templates/SubclassOf.h"
#include "AstroEntityWorldConfig.generated.h"

class UAstroEntityComponentContainer;
class UAstroEntitySystem;
class UAstroEntityWorld;

UCLASS(Blueprintable)
class UAstroEntityWorldConfig : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroEntityWorld> EntityWorldType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroEntityComponentContainer>> EntityComponentTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroEntitySystem>> EntitySystemTypes;
    
    UAstroEntityWorldConfig();
};

