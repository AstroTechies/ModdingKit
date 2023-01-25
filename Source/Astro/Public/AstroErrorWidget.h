#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AstroErrorWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ASTRO_API UAstroErrorWidget : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Message;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultTimeToDisplay;
    
public:
    UAstroErrorWidget();
};

