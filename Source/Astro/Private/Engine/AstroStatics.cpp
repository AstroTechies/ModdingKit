// Fill out your copyright notice in the Description page of Project Settings.

#include "AstroStatics.h"

void UAstroStatics::JoinToURL(UPARAM(ref)FString & Name, UObject* WorldContextObject)
{

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

/*uint64 UAstroStatics::GetGuidForController(APlayerController* controller)
{
	return 0;
}*/
