// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroStatics.h"

AAstroGameMode* UAstroStatics::GetGameMode(UObject* WorldContextObject)
{
	return nullptr;
}

AAstroGameState* UAstroStatics::GetGameState(UObject* WorldContextObject)
{
	return nullptr;
}

UAstroGameInstance* UAstroStatics::GetGameInstance(UObject* WorldContextObject)
{
	return nullptr;
}

void UAstroStatics::JoinToURL(UPARAM(ref)FString & Name, UObject* WorldContextObject)
{

}

AAstroMissionsManager* UAstroStatics::GetAstroMissionsManager(UObject* WorldContextObject)
{
	return nullptr;
}

FString UAstroStatics::GetControllingPlayerNickname()
{
	return "";
}

EPlatform UAstroStatics::GetGamePlatform()
{
	return EPlatform::PC;
}

bool UAstroStatics::IsPlatformGameConsole()
{
	return false;
}

bool UAstroStatics::IsPlatformPS4()
{
	return false;
}

bool UAstroStatics::IsPlatformUWPOrXbox()
{
	return false;
}

bool UAstroStatics::IsDedicatedServerUIEnabled()
{
	return false;
}

bool UAstroStatics::IsDedicatedServer(UObject* WorldContextObject)
{
	return false;
}

bool UAstroStatics::IsConnectedToDedicatedServer(UObject* WorldContextObject)
{
	return false;
}

bool UAstroStatics::IsLanMatch(UObject* WorldContextObject)
{
	return false;
}

bool UAstroStatics::IsShippingBuild()
{
	return false;
}

void UAstroStatics::PopulateLoadablePresets(UPanelWidget* widget)
{
	
}

void UAstroStatics::PopulateSpawnableObjects(UPanelWidget* widget, FString nameFilter)
{
	
}

void UAstroStatics::PopulateResourceTypes(UPanelWidget* widget)
{
	
}

void UAstroStatics::PopulateSaveGames(UPanelWidget* widget)
{
	
}

void UAstroStatics::ThisMethodDoesNotExist()
{

}