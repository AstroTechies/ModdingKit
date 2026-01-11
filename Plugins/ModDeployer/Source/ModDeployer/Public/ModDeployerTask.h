#pragma once

#include "CoreMinimal.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "ModDeployerDownloader.h"
#include <stdio.h>
#include <fstream>
#include <stdexcept>

class FModDeployerModule;

enum class EModDeployerTaskType : uint8
{
	RunCook = 0,
	RunPackage = 1,
	RunLaunch = 2,
	RunIntegrate = 3,
	RunAll = 4
};

class FModDeployerTask : public FNonAbandonableTask
{
public:
	UPROPERTY()
	EModDeployerTaskType TaskType;
	UPROPERTY()
	FModDeployerModule* ParentModDeployer;

    FModDeployerTask(EModDeployerTaskType taskType, FModDeployerModule* parentModDeployer)
    {
		TaskType = taskType;
		ParentModDeployer = parentModDeployer;
    }

    void DoWork()
    {
		// sanity check: don't proceed if ModFolder is still the default
		// mostly trying to avoid users accidentally pressing F5 (default keybind for Quick Deploy) when not appropriate
		if (ParentModDeployer == nullptr || ParentModDeployer->DescriptorData == nullptr) return;
		if (ParentModDeployer->DescriptorData->ModFolder == "Astro/Content/Mods/YourNameHere/TestMod")
		{
			ParentModDeployer->LogText = "Task canceled because ModFolder has not been changed from the default placeholder.\nPlease modify the fields above as needed for your mod before executing the Mod Deployer.\n";
			return;
		}

		try
		{
			bool continueExecution = true;
			ParentModDeployer->LogText = "";
			if (continueExecution && (TaskType == EModDeployerTaskType::RunCook || TaskType == EModDeployerTaskType::RunAll)) continueExecution = RunCook_Inner();
			if (continueExecution && (TaskType == EModDeployerTaskType::RunPackage || TaskType == EModDeployerTaskType::RunAll)) continueExecution = RunPackage_Inner();
			if (continueExecution && (TaskType == EModDeployerTaskType::RunIntegrate || TaskType == EModDeployerTaskType::RunAll)) continueExecution = RunIntegrate_Inner();
			if (continueExecution && (TaskType == EModDeployerTaskType::RunLaunch || TaskType == EModDeployerTaskType::RunAll)) continueExecution = RunLaunch_Inner();
			if (!continueExecution) ParentModDeployer->LogText += "Aborted task\n";
		}
		catch (const std::runtime_error& err)
		{
			FString errMsg = UTF8_TO_TCHAR(err.what());
			ParentModDeployer->LogText += TEXT("Uncaught exception occurred during task:\n") + errMsg + TEXT("\n");
			return;
		}
		catch (...)
		{
			ParentModDeployer->LogText += TEXT("Uncaught exception occurred during task: unknown\n");
			return;
		}

    }

	bool RunCook_Inner();
	bool RunPackage_Inner();
	bool RunIntegrate_Inner();
	bool RunLaunch_Inner();

    FORCEINLINE TStatId GetStatId() const
    {
        RETURN_QUICK_DECLARE_CYCLE_STAT(FMyTask, STATGROUP_ThreadPoolAsyncTasks);
    }
}; 

