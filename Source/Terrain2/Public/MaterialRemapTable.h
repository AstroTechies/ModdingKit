#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MaterialRemapTable.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable)
class UMaterialRemapTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UMaterialInterface*, UMaterialInterface*> BasicToHQMaterials;
    
    UMaterialRemapTable();

};

