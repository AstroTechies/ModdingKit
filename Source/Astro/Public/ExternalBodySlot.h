#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SlotReference.h"
#include "ExternalBodySlot.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UExternalBodySlot : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference BodySlot;
    
    UExternalBodySlot(const FObjectInitializer& ObjectInitializer);

};

