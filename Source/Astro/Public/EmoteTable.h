#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Templates/SubclassOf.h"
#include "EmoteTable.generated.h"

class UAstroEmoteDefinition;
class UAstroPlayMontageAction;

UCLASS(Blueprintable)
class UEmoteTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroPlayMontageAction> DefaultEmoteActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroEmoteDefinition*> DefaultEmoteSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UAstroEmoteDefinition>> Emotes;
    
    UEmoteTable();

};

