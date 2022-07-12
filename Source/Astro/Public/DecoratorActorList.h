#pragma once
#include "CoreMinimal.h"
#include "ActorSpecifier.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "DecoratorActorList.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UDecoratorActorList : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorSpecifier> Actors;
    
    UDecoratorActorList();
};

