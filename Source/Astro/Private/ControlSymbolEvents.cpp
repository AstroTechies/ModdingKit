#include "ControlSymbolEvents.h"

class UControlSymbol;
class UPrimitiveComponent;

void UControlSymbolEvents::DoFiredFromClick(UPrimitiveComponent* Component, FKey Key) {
}

void UControlSymbolEvents::DoFired(UControlSymbol* FiredSymbol) {
}

void UControlSymbolEvents::BindPrimitiveClicked(UPrimitiveComponent* Primitive) {
}

UControlSymbolEvents::UControlSymbolEvents() {
    this->Activation = NULL;
    this->Symbol = NULL;
    this->Control = NULL;
    this->Widget = NULL;
}

