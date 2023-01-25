#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "AstroEntityComponent.h"
#include "Templates/SubclassOf.h"
#include "AstroEntityProceduralStateComponent.generated.h"

class UItemType;

USTRUCT(BlueprintType)
struct FAstroEntityProceduralStateComponent : public FAstroEntityComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FLinearColor TintColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    float CullingDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint8 bIsBuried: 1;
    
    UPROPERTY(EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    uint64 ProceduralPlacementSaveID;
    
    ASTRO_API FAstroEntityProceduralStateComponent();
};

