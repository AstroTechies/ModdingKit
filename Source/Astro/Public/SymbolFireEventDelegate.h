#pragma once
#include "CoreMinimal.h"
#include "SymbolFireEventDelegate.generated.h"

class UControlSymbol;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSymbolFireEvent, UControlSymbol*, Symbol);

