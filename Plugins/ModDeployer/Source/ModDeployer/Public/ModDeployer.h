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
	FReply RunHelp();
	FText GetText() const;

	FString ExecuteIntegrator(FString parms);

	FReply SaveDescriptorDataSlate();
	void SaveDescriptorDataSlateLastOpened(TSharedRef<SDockTab> ClosedTab);
	FReply LoadDescriptorDataSlate();
	bool SaveDescriptorDataWithParam(bool log, bool saveLastOpened);
	bool LoadDescriptorDataWithParam(bool log, bool openLastOpened);

	void RegisterMenus();
	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	UPROPERTY()
	TSharedPtr<class FUICommandList> PluginCommands;
	UPROPERTY()
	FString LogText = "Welcome to the Mod Deployer. This plugin is designed to assist in rapidly deploying and test mods for Astroneer.\nTo see more information about this plugin, press the \"Help\" button.";
	UPROPERTY()
	UModDeployerDescriptorData* DescriptorData = nullptr;
	UPROPERTY()
	bool HaveWeCheckedForIntegratorUpdatesAlready = 0; // reset back to zero on editor relaunch
};
