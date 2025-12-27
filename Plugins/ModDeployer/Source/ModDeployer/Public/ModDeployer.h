#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "ModDeployerDescriptorData.h"
#include <filesystem>
#include <stdexcept>

class FToolBarBuilder;
class FMenuBuilder;

class FModDeployerModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	void PluginButtonClicked();
	void PluginButtonClickedQuick();

	FReply RunEverything();
	FReply RunCook();
	FReply RunPackage();
	FReply RunIntegrate();
	FReply RunLaunch();
	FText GetText() const;

	FString ExecuteIntegrator(FString parms);

	FReply SaveDescriptorDataSlate();
	void SaveDescriptorDataSlateLastOpened(TSharedRef<SDockTab> ClosedTab);
	FReply LoadDescriptorDataSlate();
	bool SaveDescriptorDataWithParam(bool log, bool saveLastOpened);
	bool LoadDescriptorDataWithParam(bool log, bool openLastOpened);

	void RegisterMenus();
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	TSharedPtr<class FUICommandList> PluginCommands;
	FString LogText = "Welcome to the Mod Deployer. This tool allows you to rapidly deploy and test your mods.";
	UModDeployerDescriptorData* DescriptorData = nullptr;
};
