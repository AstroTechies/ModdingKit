#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AstroDatum.h"
#include "AstroEntity.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FAstroEntity : public FAstroDatum {
    GENERATED_BODY()
public:
    UPROPERTY(SaveGame)
    uint8 bHasBeenInitialized: 1;
    
    UPROPERTY(SaveGame)
    FName DefinitionName;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ViewActorType;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ViewActorTemplate;
    
    UPROPERTY(BlueprintReadWrite, SaveGame, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> ViewActor;
    
    ASTRO_API FAstroEntity();
};

