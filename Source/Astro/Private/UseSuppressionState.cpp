#include "UseSuppressionState.h"

FUseSuppressionState::FUseSuppressionState() {
    this->SuppressedUseTypeFlags = EUseType::None;
    this->PerPlayerMode = FPerPlayerUseSuppressionMode::None;
}

