#include "ControlSymbolEvents.h"

UControlSymbolEvents::UControlSymbolEvents() {
    this->Activation = NULL;
    this->Symbol = NULL;
    this->Control = NULL;
    this->Widget = NULL;
}

void UControlSymbolEvents::DoFiredFromClick(UPrimitiveComponent* Component, FKey Key) {
}

void UControlSymbolEvents::DoFired(UControlSymbol* FiredSymbol) {
}

void UControlSymbolEvents::BindPrimitiveClicked(UPrimitiveComponent* Primitive) {
}


