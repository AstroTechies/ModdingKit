#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "TooltipManager.generated.h"

class UPrimitiveComponent;
class UTooltipComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UTooltipManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TMap<UPrimitiveComponent*, UTooltipComponent*> InputRespondingTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTooltipComponent*> ActiveTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTooltipComponent*> LiveTooltips;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* ExclusiveExpansionTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTooltipComponent* CursorOverTooltip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 AllTooltipsDisabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 BelongsToLocalController: 1;
    
public:
    UTooltipManager();
private:
    UFUNCTION()
    void OnTooltipPrimitiveEndCursorOver(UPrimitiveComponent* TooltipPrimitive);
    
    UFUNCTION()
    void OnTooltipPrimitiveBeginCursorOver(UPrimitiveComponent* TooltipPrimitive);
    
public:
    UFUNCTION()
    void OnExclusiveExpansionTooltipOverrideChanged();
    
};

