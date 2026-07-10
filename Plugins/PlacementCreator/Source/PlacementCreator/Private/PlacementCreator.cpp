#include "PlacementCreator.h"
#include "AssetTypeActions_ProceduralModifier.h"
#include "AssetTypeActions_ProceduralPlacement.h"
#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "FPlacementCreatorModule"

void FPlacementCreatorModule::StartupModule()
{
    IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

    TSharedRef<IAssetTypeActions> Action = MakeShareable(new FAssetTypeActions_ProceduralModifier);
    AssetTools.RegisterAssetTypeActions(Action);

    TSharedRef<IAssetTypeActions> Action2 = MakeShareable(new FAssetTypeActions_ProceduralPlacement);
    AssetTools.RegisterAssetTypeActions(Action2);
}

void FPlacementCreatorModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPlacementCreatorModule, PlacementCreator)