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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bHasBeenInitialized: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName DefinitionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> ViewActorType;
    
    UPROPERTY(EditAnywhere)
    TWeakObjectPtr<AActor> ViewActorTemplate;
    
    UPROPERTY(EditAnywhere, SaveGame)
    TWeakObjectPtr<AActor> ViewActor;
    
    ASTRO_API FAstroEntity();
};

