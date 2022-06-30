#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ClickParams.h"
#include "ClickResult.h"
#include "EClickBehavior.h"
#include "SlotReference.h"
#include "ClickQuery.generated.h"

class UPrimitiveComponent;
class AActor;
class UClickQuery;
class UStorageChassisComponent;
class APlayController;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UClickQuery : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FClickParams params;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FClickResult Result;

    UClickQuery();
    UFUNCTION(BlueprintCallable)
    void SetResultTertiary(AActor *Actor, AActor *ViewActor, EClickBehavior Behavior);

    UFUNCTION(BlueprintCallable)
    bool SetResultStorage(UStorageChassisComponent *storage, FSlotReference PrimarySlot);

    UFUNCTION(BlueprintCallable)
    bool SetResultSlotPrimaryAsConnectionOnly(FSlotReference Slot);

    UFUNCTION(BlueprintCallable)
    bool SetResultSlotPrimary(FSlotReference Slot, bool Replace);

    UFUNCTION(BlueprintCallable)
    void SetResultSecondary(AActor *Actor, AActor *ViewActor, EClickBehavior Behavior);

    UFUNCTION(BlueprintCallable)
    void SetResultPrimary(AActor *Actor, AActor *ViewActor, EClickBehavior Behavior);

    UFUNCTION(BlueprintCallable)
    void SetResultComponentPrimary(UPrimitiveComponent *Component);

    UFUNCTION(BlueprintCallable)
    void ResetPrimaryClickResult();

    UFUNCTION(BlueprintCallable)
    void ResetClickResultExceptForSecondary(AActor *Actor);

    UFUNCTION(BlueprintCallable)
    void ResetClickResultExceptForHoverComponent();

    UFUNCTION(BlueprintCallable)
    void ResetClickResult();

    UFUNCTION(BlueprintPure)
    FSlotReference QueryCameraFacingSlotFromArray(AActor *Actor, const TArray<FSlotReference> Slots);

    UFUNCTION(BlueprintPure)
    bool HavePrimaryResult() const;

    UFUNCTION(BlueprintPure)
    AActor *GetSecondaryActor() const;

    UFUNCTION(BlueprintPure)
    FSlotReference GetPrimarySlot() const;

    UFUNCTION(BlueprintPure)
    UPrimitiveComponent *GetPrimaryComponent() const;

    UFUNCTION(BlueprintPure)
    AActor *GetPrimaryActor() const;

    UFUNCTION(BlueprintPure)
    AActor *GetInteractingActor() const;

    UFUNCTION(BlueprintPure)
    UPrimitiveComponent *GetHitComponent() const;

    UFUNCTION(BlueprintPure)
    AActor *GetHitActor() const;

    UFUNCTION(BlueprintPure)
    APlayController *GetController() const;

    UFUNCTION(BlueprintPure)
    AActor *GetClickActor() const;

    UFUNCTION(BlueprintPure)
    static UClickQuery *ClickQuery();
};
