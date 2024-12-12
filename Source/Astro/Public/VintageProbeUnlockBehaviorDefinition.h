#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "AstroEntityComponentSubobjectDefinition.h"
#include "AstroNotificationUnlockAuthoringData.h"
#include "Templates/SubclassOf.h"
#include "VintageProbeUnlockBehaviorDefinition.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class ASTRO_API UVintageProbeUnlockBehaviorDefinition : public UAstroEntityComponentSubobjectDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> RealityTearObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> RealityTearFlickerObject;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference RealityTearSpawnLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationUnlockAuthoringData ActivatingPlayerUnlockNotification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroNotificationUnlockAuthoringData OtherPlayersUnlockNotification;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> UnlockItems;
    
    UVintageProbeUnlockBehaviorDefinition();

};

