#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "ModDeployerStyle.h"

class FModDeployerCommands : public TCommands<FModDeployerCommands>
{
public:

	FModDeployerCommands()
		: TCommands<FModDeployerCommands>(TEXT("ModDeployer"), NSLOCTEXT("Contexts", "ModDeployer", "ModDeployer Plugin"), NAME_None, FModDeployerStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> PluginAction;
	TSharedPtr<FUICommandInfo> PluginActionQuick;
};
