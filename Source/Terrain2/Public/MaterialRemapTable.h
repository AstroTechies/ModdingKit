#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialRemapTable.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, Blueprintable)
class UMaterialRemapTable : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<UMaterialInterface *, UMaterialInterface *> BasicToHQMaterials;

    UMaterialRemapTable();
};
