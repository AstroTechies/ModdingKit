#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SymbolEventDelegate.h"
#include "ControlSwitchDelegate.h"
#include "Components/ActorComponent.h"
#include "OnMoveDelegate.h"
#include "ToolDoClickSignalDelegate.h"
#include "EMultitoolMode.h"
#include "ClickQueryDelegateDelegate.h"
#include "ReceiveToolLocationDelegate.h"
#include "HandleToolSignalDelegate.h"
#include "MultitoolTargetSignalDelegate.h"
#include "SlotReference.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "ControlComponent.generated.h"

class AActor;
class UControlSymbolEvents;
class UStaticMesh;
class UActivation;
class APhysicalItem;
class USceneComponent;
class UControlSymbol;
class UObject;
class UControlComponent;
class APlayerController;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable)
    FOnMove OnMove;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UActivation *PlayerActivation;

    UPROPERTY(BlueprintReadWrite, Transient, meta = (AllowPrivateAccess = true))
    UActivation *UsingActivation;

    UPROPERTY(EditAnywhere)
    bool IsTool;

    UPROPERTY(EditAnywhere)
    bool PassToolToParent;

    UPROPERTY(EditAnywhere)
    float ToolMaxDistance;

    UPROPERTY(EditAnywhere)
    bool bAppliesToolTierOverride;

    UPROPERTY(EditAnywhere)
    int32 ToolTierOverride;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EMultitoolMode MultiToolMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool OnlyTraceTerrain;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AttachPing;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *WidgetComponent;

    UPROPERTY(BlueprintAssignable)
    FControlSwitch ControlSwitch;

    UPROPERTY(BlueprintAssignable)
    FSymbolEvent SymbolEvent;

    UPROPERTY(BlueprintAssignable)
    FClickQueryDelegate ToolClickQuery;

    UPROPERTY(BlueprintAssignable)
    FReceiveToolLocation OnReceiveToolLocation;

    UPROPERTY(BlueprintAssignable, BlueprintCallable)
    FHandleToolSignal ToolTick;

    UPROPERTY(BlueprintAssignable)
    FMultitoolTargetSignal ToolMultitoolLocation;

    UPROPERTY(BlueprintAssignable)
    FToolDoClickSignal ToolDoInteraction;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference OutSlot;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ChildToolSlots;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *AttachOwner;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TArray<UControlSymbol *> EnabledControlSymbols;

private:
    UPROPERTY()
    TMap<UObject *, UControlSymbolEvents *> ControlSymbolEvents;

    UPROPERTY(Export)
    TMap<UObject *, UControlComponent *> CollectedControls;

    UPROPERTY()
    TArray<AActor *> PingingActors;

    UPROPERTY(Export)
    UControlComponent *controlOwner;

    UPROPERTY(Transient)
    APlayerController *LastController;

public:
    UControlComponent();
    UFUNCTION(BlueprintCallable)
    void SetMoveInputs(APlayerController *Controller, const FVector &Direction);

    UFUNCTION(BlueprintCallable)
    void SetControlOwner(UControlComponent *NewControlOwner);

    UFUNCTION(BlueprintCallable)
    void PingSymbol(TSubclassOf<UControlSymbol> Symbol);

    UFUNCTION(BlueprintCallable)
    static void PingObjectSymbolAtLocation(UObject *WorldContextObject, UControlSymbol *Symbol, const FTransform &symbolTransform, UStaticMesh *MeshUsedAsIcon);

    UFUNCTION(BlueprintCallable)
    void PingObjectSymbol(UControlSymbol *Symbol);

private:
    UFUNCTION()
    void OnChildToolSlotRelease(APhysicalItem *Item);

    UFUNCTION()
    void OnChildToolSlotAdd(APhysicalItem *Item);

    UFUNCTION()
    void OnActivateChange(bool Enable);

public:
    UFUNCTION(BlueprintPure)
    bool IsPlayerActivated();

    UFUNCTION(BlueprintPure)
    bool IsActivated();

    UFUNCTION(BlueprintPure)
    UControlSymbolEvents *GetObjectControlSymbolEvents(UControlSymbol *Symbol);

    UFUNCTION(BlueprintPure)
    UControlComponent *GetMovementTarget();

    UFUNCTION(BlueprintPure)
    UControlSymbolEvents *GetControlSymbolEvents(TSubclassOf<UControlSymbol> Symbol);

    UFUNCTION(BlueprintPure)
    static UControlComponent *GetActorControlComponent(AActor *Actor);

    UFUNCTION(BlueprintPure)
    UControlComponent *GetActiveControl();

    UFUNCTION(BlueprintCallable)
    void FireSymbolEvent(TSubclassOf<UControlSymbol> Symbol);

    UFUNCTION(BlueprintCallable)
    void FireObjectSymbolEvent(UControlSymbol *Symbol);

    UFUNCTION(BlueprintCallable)
    UControlSymbolEvents *EnableObjectControlSymbol(UControlSymbol *Symbol, bool Enable);

    UFUNCTION(BlueprintCallable)
    UControlSymbolEvents *EnableControlSymbol(TSubclassOf<UControlSymbol> Symbol, bool Enable);
};
