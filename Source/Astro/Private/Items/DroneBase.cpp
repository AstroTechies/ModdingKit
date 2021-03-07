
#include "DroneBase.h"

void ADroneBase::AuthorityLaunchDrone(APlayController* owningController){
}

void ADroneBase::AuthorityEmergencyRecallDrone(){
}

void ADroneBase::AuthorityRecallDrone(){
}

ASolarBody* ADroneBase::GetLocalSolarBody(){
	return nullptr;
}

float ADroneBase::GetCurrentFOV(){
	return 0;
}

void ADroneBase::SetRiseInputActive(){
}

void ADroneBase::SetRiseInputInactive(){
}

void ADroneBase::ZoomIn(){
}

void ADroneBase::ZoomOut(){
}

void ADroneBase::HandlePlacedInSlot(){
}

void ADroneBase::HandlePlayerReachedSpaceInShuttle(){
}

void ADroneBase::NudgeFlightSpeedSlower(){
}

void ADroneBase::NudgeFlightSpeedFaster(){
}

void ADroneBase::OnRep_FlightState(){
}

bool ADroneBase::IsLocallyControlled(){
	return true;
}