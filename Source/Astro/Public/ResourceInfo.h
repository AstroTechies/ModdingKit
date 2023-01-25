#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "TextDelegateDelegate.h"
#include "ResourceInfo.generated.h"

class APhysicalItem;
class UAdaptiveTickComponent;
class UItemType;
class UPrimitiveComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASTRO_API AResourceInfo : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAdaptiveTickComponent* AdaptiveTick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> ItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> storedSubItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Hovering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* ItemParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* ActorParent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference SlotParent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTextDelegate SetDescription;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetDistance;
    
    AResourceInfo();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTextVisible(bool Visible);
    
    UFUNCTION(BlueprintCallable)
    void SetPrimaryItemTypeAndStoredSubType(TSubclassOf<UItemType> primaryItemType, TSubclassOf<UItemType> storedSubType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSpawn();
    
    UFUNCTION(BlueprintCallable)
    void MeshCursorEnd(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void MeshCursorBegin(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void MeshClicked(UPrimitiveComponent* Component, FKey Key);
    
};

