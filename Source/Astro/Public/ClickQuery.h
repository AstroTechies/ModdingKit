#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ClickParams.h"
#include "ClickResult.h"
#include "EClickBehavior.h"
#include "SlotReference.h"
#include "ClickQuery.generated.h"

class AActor;
class APlayController;
class UClickQuery;
class UPrimitiveComponent;
class UStorageChassisComponent;

UCLASS(Blueprintable)
class ASTRO_API UClickQuery : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickParams params;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FClickResult Result;
    
    UClickQuery();

    UFUNCTION(BlueprintCallable)
    void SetResultTertiary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior);
    
    UFUNCTION(BlueprintCallable)
    bool SetResultStorage(UStorageChassisComponent* storage, FSlotReference PrimarySlot);
    
    UFUNCTION(BlueprintCallable)
    bool SetResultSlotPrimaryAsConnectionOnly(FSlotReference Slot);
    
    UFUNCTION(BlueprintCallable)
    bool SetResultSlotPrimary(FSlotReference Slot, bool Replace);
    
    UFUNCTION(BlueprintCallable)
    void SetResultSecondary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior);
    
    UFUNCTION(BlueprintCallable)
    void SetResultPrimary(AActor* Actor, AActor* ViewActor, EClickBehavior Behavior);
    
    UFUNCTION(BlueprintCallable)
    void SetResultComponentPrimary(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void ResetPrimaryClickResult();
    
    UFUNCTION(BlueprintCallable)
    void ResetClickResultExceptForSecondary(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void ResetClickResultExceptForHoverComponent();
    
    UFUNCTION(BlueprintCallable)
    void ResetClickResult();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference QueryCameraFacingSlotFromArray(AActor* Actor, const TArray<FSlotReference> Slots);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HavePrimaryResult() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSecondaryActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FSlotReference GetPrimarySlot() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrimitiveComponent* GetPrimaryComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPrimaryActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteractingActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetHitLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UPrimitiveComponent* GetHitComponent() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetHitActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayController* GetController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetClickActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UClickQuery* ClickQuery();
    
};

