#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "InputCoreTypes.h"
#include "SymbolFireEventDelegate.h"
#include "ControlSymbolEvents.generated.h"

class AActor;
class UActivation;
class UControlComponent;
class UControlSymbol;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASTRO_API UControlSymbolEvents : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSymbolFireEvent Fired;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UActivation* Activation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UControlSymbol* Symbol;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlComponent* Control;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Widget;
    
    UControlSymbolEvents();

    UFUNCTION(BlueprintCallable)
    void DoFiredFromClick(UPrimitiveComponent* Component, FKey Key);
    
    UFUNCTION(BlueprintCallable)
    void DoFired(UControlSymbol* FiredSymbol);
    
    UFUNCTION(BlueprintCallable)
    void BindPrimitiveClicked(UPrimitiveComponent* Primitive);
    
};

