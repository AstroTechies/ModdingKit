#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AstroDatumRef.h"
#include "AstroEntityDefinition.h"
#include "ActorEntityLinkComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UActorEntityLinkComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroEntityDefinition EntityDefinition;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FAstroDatumRef EntityRef;
    
public:
    UActorEntityLinkComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawnedFromEntity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAstroDatumRef GetEntityDatumRef(bool& bOutSuccess) const;
    
};

