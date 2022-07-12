#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "AstroEntityTaskManager.generated.h"

class UAstroEntityWorld;
class UAstroDatumContainer;

UCLASS(Blueprintable)
class ASTRO_API UAstroEntityTaskManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAstroEntityWorld* EntityWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UAstroDatumContainer>> DependentDatumContainerTypes;
    
public:
    UAstroEntityTaskManager();
};

