#pragma once
#include "CoreMinimal.h"
#include "SymbolEventDelegate.generated.h"

class UControlSymbol;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSymbolEvent, UControlSymbol*, Symbol);

