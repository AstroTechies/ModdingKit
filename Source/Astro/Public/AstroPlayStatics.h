#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BlueprintFunctionLibrary -FallbackName=BlueprintFunctionLibrary
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
#include "VoxelMaterial.h"
#include "ENavpointGroup.h"
#include "Navpoint.h"
#include "Templates/SubclassOf.h"
#include "AstroPlayStatics.generated.h"

class AActor;
class AAstroCharacter;
class AAstroPlanet;
class APhysicalItem;
class APlayController;
class APlayerController;
class UChildActorComponent;
class UControlSymbol;
class UItemType;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class UTexture;

UCLASS(Blueprintable)
class ASTRO_API UAstroPlayStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroPlayStatics();
    UFUNCTION(BlueprintCallable)
    static void WeldToPreserveContraints(AActor* Actor, UPrimitiveComponent* Parent);
    
    UFUNCTION(BlueprintCallable)
    static AActor* WeldChildActor(UChildActorComponent* Slot);
    
    UFUNCTION(BlueprintCallable)
    static void ServerClickActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void ServerClick(UPrimitiveComponent* Primitive);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RestoreInputModeToGameFromUI(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool RaycastVoxels(AAstroPlanet* Planet, const FVector& RayStart, const FVector& RayEnd, FHitResult& OutHit, float Accuracy);
    
    UFUNCTION(BlueprintCallable)
    static void PlaySurfaceFoley(const FString& SoundEvent, USceneComponent* AttachToComponent, FName AttachPointName, bool bStopWhenAttachedToDestroyed);
    
    UFUNCTION(BlueprintCallable)
    static bool MoveToSafety(AActor* actorToMove, UPrimitiveComponent* actorCollisionComponent, FVector testConstellationUpVector, float testGrowthIncrement);
    
    UFUNCTION(BlueprintCallable)
    static void LocalClick(UPrimitiveComponent* Primitive);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsCharacterInFlyingShuttle(AAstroCharacter* AstroCharacter);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetTradeOutputAmount(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, const TArray<APhysicalItem*>& InputItems);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* GetTopmostParentActor(AActor* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPrimitiveComponent* GetSimulatingParent(USceneComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UPrimitiveComponent* GetSimulatingAttachParent(USceneComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetRopeInterpNormal(const FVector& Start, const FVector& StartNormal, const FVector& End, const FVector& EndNormal, float NormalScale, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetRopeInterpLocation(const FVector& Start, const FVector& StartNormal, const FVector& End, const FVector& EndNormal, float NormalScale, float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<TSubclassOf<UItemType>> GetPossibleOutputTypes(TSubclassOf<UItemType> InputItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<TSubclassOf<UItemType>> GetPossibleInputTypes();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static APlayController* GetPlayController(const UObject* WorldContextObject, int32 Index);
    
    UFUNCTION(BlueprintCallable)
    static bool GetNavpoint(FGuid NavpointID, FNavpoint& outNavpoint);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetMoveDirection3D(APlayerController* Controller, AActor* Actor, const FVector ControlDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetMoveDirection(APlayerController* Controller, AActor* Actor, const FVector2D ControlDirection);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetMinimumDiscreteTradeRatioBetweenItems(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, int32& OutDiscreteInputRatioTerm, int32& OutDiscreteOutputRatioTerm);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static APlayController* GetLocalPlayController(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AAstroCharacter* GetLocalAstroCharacter(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UItemType* GetItemTypeDefault(TSubclassOf<UItemType> Type);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static APlayerController* GetCurrentInputController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UControlSymbol* GetControlSymbolDefault(TSubclassOf<UControlSymbol> Type);
    
    UFUNCTION(BlueprintCallable)
    static TArray<APhysicalItem*> GetConsumedInputItemsForTradeOutput(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, int32 TargetOutputAmount, const TArray<APhysicalItem*>& InputItems);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static TArray<APlayController*> GetAllPlayControllers(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static FVoxelMaterial DowncastTerrainMaterial(UObject* WorldContextObject, const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    static void ClickActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void Click(UPrimitiveComponent* Primitive);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static FGuid AuthorityTrackNavpointOnCurrentPlanet(const FNavpoint& newNavpoint);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthoritySetNavpointOverrideIconOnCurrentPlanet(FGuid NavpointID, UTexture* Icon);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthoritySetNavpointOverrideColorOnCurrentPlanet(FGuid NavpointID, FLinearColor Color);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthoritySetNavpointEnabledOnCurrentPlanet(FGuid NavpointID, bool IsEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthorityRemoveNavpointOnCurrentPlanet(FGuid NavpointID);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static FGuid AuthorityPushNavpointGroupSettingOnGivenPlanet(AAstroPlanet* Planet, ENavpointGroup Group, bool IsEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static FGuid AuthorityPushNavpointGroupSettingOnCurrentPlanet(AActor* planetContextObject, ENavpointGroup Group, bool IsEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void AuthorityPopNavpointGroupSetting(FGuid settingID);
    
    UFUNCTION(BlueprintCallable)
    static void AddComponentForceAtLocation(USceneComponent* Component, const FVector& force, const FVector& Location);
    
};

