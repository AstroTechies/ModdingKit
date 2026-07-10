#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

class FAssetTypeActions_ProceduralPlacement : public FAssetTypeActions_Base
{
public:
    virtual FText GetName() const override { return INVTEXT("Procedural Placement"); }
    virtual FColor GetTypeColor() const override { return FColor(0, 128, 255); }
    virtual UClass* GetSupportedClass() const override;
    virtual uint32 GetCategories() override;
};