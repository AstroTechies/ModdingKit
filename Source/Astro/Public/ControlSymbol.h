#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ControlSymbol.generated.h"

class AActor;

UCLASS(Blueprintable)
class ASTRO_API UControlSymbol : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText AllCapsName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText TooltipSubtitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SoundEvent;
    
    UControlSymbol();

    UFUNCTION(BlueprintCallable)
    void ApplyToIconActor(AActor* Actor);
    
};

