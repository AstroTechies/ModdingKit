#pragma once
#include "CoreMinimal.h"
#include "TradeShipDockComponent.h"
#include "TradeShipDockComponent_ItemDrive.generated.h"

class UItemDriveComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTradeShipDockComponent_ItemDrive : public UTradeShipDockComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemDriveComponent* ItemDriveComponent;
    
public:
    UTradeShipDockComponent_ItemDrive(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void HandleActiveEventChanged();
    
};

