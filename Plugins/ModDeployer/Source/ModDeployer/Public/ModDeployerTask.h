#pragma once

#include "CoreMinimal.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "ModDeployerDownloader.h"
#include <stdio.h>
#include <fstream>

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
	EModDeployerTaskType TaskType;
	FModDeployerModule* ParentModDeployer;

    FModDeployerTask(EModDeployerTaskType taskType, FModDeployerModule* parentModDeployer)
    {
		TaskType = taskType;
		ParentModDeployer = parentModDeployer;
    }

    void DoWork()
    {
		ParentModDeployer->LogText = "";
		if (TaskType == EModDeployerTaskType::RunCook || TaskType == EModDeployerTaskType::RunAll) RunCook_Inner();
		if (TaskType == EModDeployerTaskType::RunPackage || TaskType == EModDeployerTaskType::RunAll) RunPackage_Inner();
		if (TaskType == EModDeployerTaskType::RunIntegrate || TaskType == EModDeployerTaskType::RunAll) RunIntegrate_Inner();
		if (TaskType == EModDeployerTaskType::RunLaunch || TaskType == EModDeployerTaskType::RunAll) RunLaunch_Inner();
    }

	void RunCook_Inner();
	void RunPackage_Inner();
	void RunIntegrate_Inner();
	void RunLaunch_Inner();

    FORCEINLINE TStatId GetStatId() const
    {
        RETURN_QUICK_DECLARE_CYCLE_STAT(FMyTask, STATGROUP_ThreadPoolAsyncTasks);
    }
}; 

