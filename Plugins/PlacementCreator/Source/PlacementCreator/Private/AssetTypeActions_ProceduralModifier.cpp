#include "AssetTypeActions_ProceduralModifier.h"
#include "ProceduralModifier.h"

UClass* FAssetTypeActions_ProceduralModifier::GetSupportedClass() const
{
    return UProceduralModifier::StaticClass();
}

uint32 FAssetTypeActions_ProceduralModifier::GetCategories()
{
    return EAssetTypeCategories::Misc; 
}