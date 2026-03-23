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

	void DoWork();
	bool RunCook_Inner();
	bool RunPackage_Inner();
	bool RunIntegrate_Inner();
	bool RunLaunch_Inner();

    FORCEINLINE TStatId GetStatId() const
    {
        RETURN_QUICK_DECLARE_CYCLE_STAT(FMyTask, STATGROUP_ThreadPoolAsyncTasks);
    }
}; 

