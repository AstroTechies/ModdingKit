#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnMoveDelegate.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ClickQueryDelegateDelegate.h"
#include "EMultitoolMode.h"
#include "SymbolEventDelegate.h"
#include "ControlSwitchDelegate.h"
#include "ReceiveToolLocationDelegate.h"
#include "HandleToolSignalDelegate.h"
#include "MultitoolTargetSignalDelegate.h"
#include "ToolDoClickSignalDelegate.h"
#include "SlotReference.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
#include "ControlComponent.generated.h"

class UActivation;
class USceneComponent;
class UControlSymbolEvents;
class UStaticMesh;
class AActor;
class UControlSymbol;
class UObject;
class UControlComponent;
class APlayerController;
class APhysicalItem;

UCLASS(Blueprintable, ClassGroup = Custom, meta = (BlueprintSpawnableComponent))
class ASTRO_API UControlComponent : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FOnMove OnMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UActivation *PlayerActivation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UActivation *UsingActivation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool IsTool;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool PassToolToParent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ToolMaxDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bAppliesToolTierOverride;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 ToolTierOverride;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    EMultitoolMode MultiToolMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool OnlyTraceTerrain;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool AttachPing;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *WidgetComponent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FControlSwitch ControlSwitch;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSymbolEvent SymbolEvent;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FClickQueryDelegate ToolClickQuery;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FReceiveToolLocation OnReceiveToolLocation;

    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FHandleToolSignal ToolTick;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FMultitoolTargetSignal ToolMultitoolLocation;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FToolDoClickSignal ToolDoInteraction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FSlotReference OutSlot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSlotReference> ChildToolSlots;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    AActor *AttachOwner;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<UControlSymbol *> EnabledControlSymbols;

private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<UObject *, UControlSymbolEvents *> ControlSymbolEvents;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    TMap<UObject *, UControlComponent *> CollectedControls;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<AActor *> PingingActors;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta = (AllowPrivateAccess = true))
    UControlComponent *controlOwner;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    APlayerController *LastController;

public:
    UControlComponent();
    UFUNCTION(BlueprintCallable)
    void SetMoveInputs(APlayerController *Controller, const FVector &Direction);

    UFUNCTION(BlueprintCallable)
    void SetControlOwner(UControlComponent *NewControlOwner);

    UFUNCTION(BlueprintCallable)
    void PingSymbol(TSubclassOf<UControlSymbol> Symbol);

    UFUNCTION(meta = (WorldContext = "WorldContextObject"), BlueprintCallable)
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
