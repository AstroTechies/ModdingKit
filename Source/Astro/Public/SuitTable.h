#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SuitDefinition.h"
#include "SuitTable.generated.h"

UCLASS(Blueprintable)
class USuitTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSuitDefinition> Suits;
    
    USuitTable();

};

