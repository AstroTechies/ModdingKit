#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputCoreTypes.h"
#include "SymbolFireEventDelegate.h"
#include "ControlSymbolEvents.generated.h"

class UPrimitiveComponent;
class UControlComponent;
class UActivation;
class UControlSymbol;
class AActor;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UControlSymbolEvents : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FSymbolFireEvent Fired;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UActivation *Activation;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UControlSymbol *Symbol;

    UPROPERTY(Export)
    UControlComponent *Control;

    UPROPERTY()
    AActor *Widget;

    UControlSymbolEvents();
    UFUNCTION()
    void DoFiredFromClick(UPrimitiveComponent *Component, FKey Key);

    UFUNCTION()
    void DoFired(UControlSymbol *FiredSymbol);

    UFUNCTION(BlueprintCallable)
    void BindPrimitiveClicked(UPrimitiveComponent *Primitive);
};
