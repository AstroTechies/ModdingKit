#include "InitialClientStateParams.h"

FInitialClientStateParams::FInitialClientStateParams() {
    this->IsReturningPlayer = false;
    this->GameUsesTitleMenu = false;
    this->GameUsesIntroCinematic = false;
    this->IsHostDedicatedServer = false;
    this->IsJoiningCreativeModeGame = false;
    this->IsJoiningGameWithCreativeModeActive = false;
}

