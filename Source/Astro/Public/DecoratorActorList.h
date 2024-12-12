#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActorSpecifier.h"
#include "DecoratorActorList.generated.h"

UCLASS(Blueprintable)
class ASTRO_API UDecoratorActorList : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FActorSpecifier> Actors;
    
    UDecoratorActorList();

};

