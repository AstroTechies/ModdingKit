#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "ItemDriveRequestComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UItemDriveRequestComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, SaveGame, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    FGuid ItemGUID;

protected:
    UPROPERTY(SaveGame)
    uint8 GuidInitialized : 1;

public:
    UItemDriveRequestComponent();
};
