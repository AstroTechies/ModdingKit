#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "TextDelegateDelegate.h"
#include "SlotReference.h"
#include "InputCoreTypes.h"
#include "ResourceInfo.generated.h"

class UAdaptiveTickComponent;
class UStaticMeshComponent;
class UItemType;
class APhysicalItem;
class UPrimitiveComponent;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AResourceInfo : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UAdaptiveTickComponent *AdaptiveTick;

    UPROPERTY(BlueprintReadWrite, Export, VisibleAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *StaticMesh;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> ItemType;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    TSubclassOf<UItemType> storedSubItemType;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool Hovering;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    APhysicalItem *ItemParent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    AActor *ActorParent;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FSlotReference SlotParent;

    UPROPERTY(BlueprintAssignable)
    FTextDelegate SetDescription;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OffsetDistance;

    AResourceInfo();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTextVisible(bool Visible);

    UFUNCTION(BlueprintCallable)
    void SetPrimaryItemTypeAndStoredSubType(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> storedSubType);

    UFUNCTION(BlueprintImplementableEvent)
    void OnSpawn();

    UFUNCTION()
    void MeshCursorEnd(UPrimitiveComponent *Component);

    UFUNCTION()
    void MeshCursorBegin(UPrimitiveComponent *Component);

    UFUNCTION()
    void MeshClicked(UPrimitiveComponent *Component, FKey Key);
};
