#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "ClickQueryDelegateDelegate.h"
#include "ControlSwitchDelegate.h"
#include "EMultitoolMode.h"
#include "HandleToolSignalDelegate.h"
#include "MultitoolTargetSignalDelegate.h"
#include "OnMoveDelegate.h"
#include "ReceiveToolLocationDelegate.h"
#include "SlotReference.h"
#include "SymbolEventDelegate.h"
#include "Templates/SubclassOf.h"
#include "ToolDoClickSignalDelegate.h"
#include "ControlComponent.generated.h"

class AActor;
class APhysicalItem;
class APlayerController;
class UActivation;
class UControlComponent;
class UControlSymbol;
class UControlSymbolEvents;
class UObject;
class USceneComponent;
class UStaticMesh;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UControlComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMove OnMove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActivation* PlayerActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActivation* UsingActivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsTool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PassToolToParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ToolMaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAppliesToolTierOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ToolTierOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultitoolMode MultiToolMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OnlyTraceTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AttachPing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* WidgetComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControlSwitch ControlSwitch;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSymbolEvent SymbolEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickQueryDelegate ToolClickQuery;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReceiveToolLocation OnReceiveToolLocation;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHandleToolSignal ToolTick;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultitoolTargetSignal ToolMultitoolLocation;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FToolDoClickSignal ToolDoInteraction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference OutSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> ChildToolSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AttachOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UControlSymbol*> EnabledControlSymbols;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<UObject*, UControlSymbolEvents*> ControlSymbolEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<UObject*, UControlComponent*> CollectedControls;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PingingActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UControlComponent* controlOwner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerController* LastController;
    
public:
    UControlComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetMoveInputs(APlayerController* Controller, const FVector& Direction);
    
    UFUNCTION(BlueprintCallable)
    void SetControlOwner(UControlComponent* NewControlOwner);
    
    UFUNCTION(BlueprintCallable)
    void PingSymbol(TSubclassOf<UControlSymbol> Symbol);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void PingObjectSymbolAtLocation(UObject* WorldContextObject, UControlSymbol* Symbol, const FTransform& symbolTransform, UStaticMesh* MeshUsedAsIcon);
    
    UFUNCTION(BlueprintCallable)
    void PingObjectSymbol(UControlSymbol* Symbol);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnChildToolSlotRelease(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnChildToolSlotAdd(APhysicalItem* Item);
    
    UFUNCTION(BlueprintCallable)
    void OnActivateChange(bool Enable);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerActivated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActivated();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UControlSymbolEvents* GetObjectControlSymbolEvents(UControlSymbol* Symbol);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UControlComponent* GetMovementTarget();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UControlSymbolEvents* GetControlSymbolEvents(TSubclassOf<UControlSymbol> Symbol);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UControlComponent* GetActorControlComponent(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UControlComponent* GetActiveControl();
    
    UFUNCTION(BlueprintCallable)
    void FireSymbolEvent(TSubclassOf<UControlSymbol> Symbol);
    
    UFUNCTION(BlueprintCallable)
    void FireObjectSymbolEvent(UControlSymbol* Symbol);
    
    UFUNCTION(BlueprintCallable)
    UControlSymbolEvents* EnableObjectControlSymbol(UControlSymbol* Symbol, bool Enable);
    
    UFUNCTION(BlueprintCallable)
    UControlSymbolEvents* EnableControlSymbol(TSubclassOf<UControlSymbol> Symbol, bool Enable);
    
};

