#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "Templates/SubclassOf.h"
#include "AstroEntityTaskManager.generated.h"

class UAstroDatumContainer;
class UAstroEntityWorld;

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

