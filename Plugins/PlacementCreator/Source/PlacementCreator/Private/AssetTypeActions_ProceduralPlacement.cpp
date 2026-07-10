#include "AssetTypeActions_ProceduralPlacement.h"
#include "ProceduralPlacement.h"

UClass* FAssetTypeActions_ProceduralPlacement::GetSupportedClass() const
{
    return UProceduralPlacement::StaticClass();
}

uint32 FAssetTypeActions_ProceduralPlacement::GetCategories()
{
    return EAssetTypeCategories::Misc; 
}