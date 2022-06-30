#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Engine/DeveloperSettings.h"
#include "Curves/CurveFloat.h"
#include "UISettings.generated.h"

class UUserWidget;
class UAstroErrorWidget;
class UVirtualCursorWidget;
class UUISettings;

UCLASS(Blueprintable, BlueprintType, DefaultConfig, Config = Game)
class ASTRO_API UUISettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> EarlyAccessWatermark;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool DisplayEarlyAccessWatermark;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<UUserWidget> ExperimentalWatermark;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool DisplayExperimentalWatermark;

private:
    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UUserWidget> LoadingScreenWidget;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UUserWidget> WaitForPlayerInputWidget;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UUserWidget> ConfirmChangeProfilesWidget;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UUserWidget> ReconnectControllerWidget;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UUserWidget> PlayTogetherPromptWidget;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UAstroErrorWidget> ErrorWidgetClass;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UAstroErrorWidget> SessionOperationInProgressWidgetClass;

    UPROPERTY(Config, EditAnywhere)
    TSubclassOf<UVirtualCursorWidget> WidgetClass;

    UPROPERTY(Config, EditAnywhere)
    float CursorSize;

    UPROPERTY(Config, EditAnywhere)
    float DeadZone;

    UPROPERTY(Config, EditAnywhere)
    float MaxSpeed;

    UPROPERTY(Config, EditAnywhere)
    float MaxSpeedWhenHovered;

    UPROPERTY(Config, EditAnywhere)
    float MinSpeed;

    UPROPERTY(Config, EditAnywhere)
    float AccelerationMultiplier;

    UPROPERTY(Config, EditAnywhere)
    FRuntimeFloatCurve MovementCurve;

    UPROPERTY(Config, EditAnywhere)
    bool bHasIntertia;

    UPROPERTY(Config, EditAnywhere)
    float DragCoefficient;

    UPROPERTY(Config, EditAnywhere)
    float DragCoefficientWhenHovered;

public:
    UUISettings();
    UFUNCTION(BlueprintPure)
    static UUISettings *GetAstroUISettings();
};
