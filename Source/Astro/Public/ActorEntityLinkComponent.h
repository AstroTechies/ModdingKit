#pragma once
#include "CoreMinimal.h"
#include "AstroEntityDefinition.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "AstroDatumRef.h"
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
    UActorEntityLinkComponent();
    UFUNCTION(BlueprintPure)
    bool IsSpawnedFromEntity() const;
    
    UFUNCTION(BlueprintPure)
    FAstroDatumRef GetEntityDatumRef(bool& bOutSuccess) const;
    
};

