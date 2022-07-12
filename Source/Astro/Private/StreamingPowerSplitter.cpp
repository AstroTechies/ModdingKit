#include "StreamingPowerSplitter.h"
#include "Net/UnrealNetwork.h"

class ASlotConnection;
class UActorStreamingPowerCableComponent;

void AStreamingPowerSplitter::OnRep_SplitterData() {
}

void AStreamingPowerSplitter::HandleCableConnectionMade(FSlotReference SlotRef, ASlotConnection* Connection) {
}

void AStreamingPowerSplitter::HandleCableConnectionInterrupted(UActorStreamingPowerCableComponent* powerCable, bool bInterrupted) {
}

void AStreamingPowerSplitter::HandleCableConnectionBroken(FSlotReference SlotRef, ASlotConnection* Connection) {
}

EPowerCableConnectionDirection AStreamingPowerSplitter::GetDirectionOfCableForSlot(const FSlotReference& ConnectedSlot) {
    return EPowerCableConnectionDirection::InputConnection;
}

void AStreamingPowerSplitter::ChangePowerSplitRatios(const TArray<float>& SplitRatios) {
}

void AStreamingPowerSplitter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AStreamingPowerSplitter, SplitterRepData);
}

AStreamingPowerSplitter::AStreamingPowerSplitter() {
}

