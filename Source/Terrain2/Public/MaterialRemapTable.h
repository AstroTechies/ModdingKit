#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
#include "MaterialRemapTable.generated.h"

class UMaterialInterface;

UCLASS()
class UMaterialRemapTable : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(EditDefaultsOnly)
    TMap<UMaterialInterface*, UMaterialInterface*> BasicToHQMaterials;
    
    UMaterialRemapTable();
};

