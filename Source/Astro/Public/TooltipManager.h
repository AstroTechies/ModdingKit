#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TooltipManager.generated.h"

class UPrimitiveComponent;
class UTooltipComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTooltipManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, UTooltipComponent*> InputRespondingTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTooltipComponent*> ActiveTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTooltipComponent*> LiveTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* ExclusiveExpansionTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CursorOverTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 AllTooltipsDisabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 BelongsToLocalController: 1;
    
public:
    UTooltipManager(const FObjectInitializer& ObjectInitializer);

private:
    UFUNCTION(BlueprintCallable)
    void OnTooltipPrimitiveEndCursorOver(UPrimitiveComponent* TooltipPrimitive);
    
    UFUNCTION(BlueprintCallable)
    void OnTooltipPrimitiveBeginCursorOver(UPrimitiveComponent* TooltipPrimitive);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnExclusiveExpansionTooltipOverrideChanged();
    
};

