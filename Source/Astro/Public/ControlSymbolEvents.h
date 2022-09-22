#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "SymbolFireEventDelegate.h"
#include "ControlSymbolEvents.generated.h"

class UControlComponent;
class UControlSymbol;
class UActivation;
class UPrimitiveComponent;
class AActor;

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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UControlComponent* Control;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Widget;
    
    UControlSymbolEvents();
    UFUNCTION()
    void DoFiredFromClick(UPrimitiveComponent* Component, FKey Key);
    
    UFUNCTION()
    void DoFired(UControlSymbol* FiredSymbol);
    
    UFUNCTION(BlueprintCallable)
    void BindPrimitiveClicked(UPrimitiveComponent* Primitive);
    
};

