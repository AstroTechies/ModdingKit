#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SignalDelegate.h"
#include "UObject/NoExportTypes.h"
#include "ECrackableMethod.h"
#include "InputCoreTypes.h"
#include "Crackable.generated.h"

class UPrimitiveComponent;
class UChildActorComponent;
class UCrackable;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UCrackable : public USceneComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FSignal OnCracked;

    UPROPERTY(BlueprintAssignable)
    FSignal OnClosed;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFullyCracked;

    UPROPERTY(BlueprintAssignable)
    FSignal OnFullyClosed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ECrackableMethod Method;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool UseSimulatingForOrigin;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CrackingSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ScreenScaleRatio;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector CameraSpaceOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool ClickToCrack;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HoverHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool HideWhenFullyCracked;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AddCameraTargetOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float HideThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float PivotAngle;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool cracked;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float TargetCrackedValue;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    float CrackedValue;

    UPROPERTY(EditAnywhere)
    float CameraCollisionOffset;

    UPROPERTY(EditAnywhere)
    float CameraCollisionSize;

    UPROPERTY(EditAnywhere)
    uint8 bShowCollisionDebug : 1;

protected:
    UPROPERTY(Export)
    USceneComponent *Origin;

    UPROPERTY(Export)
    TArray<UPrimitiveComponent *> Primitives;

    UPROPERTY(Export)
    TArray<UCrackable *> Children;

    UPROPERTY(Export)
    TArray<UChildActorComponent *> ChildActors;

public:
    UCrackable();
    UFUNCTION(BlueprintCallable)
    void ToggleCracked();

    UFUNCTION(BlueprintCallable)
    void SetCracked(bool NewCracked);

protected:
    UFUNCTION()
    void OnMoved(bool FromTool);

    UFUNCTION()
    void OnComponentClicked(UPrimitiveComponent *Component, FKey Key);

    UFUNCTION()
    void OnClickUnhandled();

public:
    UFUNCTION(BlueprintCallable)
    void AddChildActor(UChildActorComponent *ChildActor);

    UFUNCTION(BlueprintCallable)
    void AddChild(UCrackable *Child);
};
