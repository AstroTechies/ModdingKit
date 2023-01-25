#include "AstroPlayStatics.h"
#include "Templates/SubclassOf.h"

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

void UAstroPlayStatics::WeldToPreserveContraints(AActor* Actor, UPrimitiveComponent* Parent) {
}

AActor* UAstroPlayStatics::WeldChildActor(UChildActorComponent* Slot) {
    return NULL;
}

void UAstroPlayStatics::ServerClickActor(AActor* Actor) {
}

void UAstroPlayStatics::ServerClick(UPrimitiveComponent* Primitive) {
}

void UAstroPlayStatics::RestoreInputModeToGameFromUI(UObject* WorldContextObject) {
}

bool UAstroPlayStatics::RaycastVoxels(AAstroPlanet* Planet, const FVector& RayStart, const FVector& RayEnd, FHitResult& OutHit, float Accuracy) {
    return false;
}

void UAstroPlayStatics::PlaySurfaceFoley(const FString& SoundEvent, USceneComponent* AttachToComponent, FName AttachPointName, bool bStopWhenAttachedToDestroyed) {
}

bool UAstroPlayStatics::MoveToSafety(AActor* actorToMove, UPrimitiveComponent* actorCollisionComponent, FVector testConstellationUpVector, float testGrowthIncrement) {
    return false;
}

void UAstroPlayStatics::LocalClick(UPrimitiveComponent* Primitive) {
}

bool UAstroPlayStatics::IsCharacterInFlyingShuttle(AAstroCharacter* AstroCharacter) {
    return false;
}

int32 UAstroPlayStatics::GetTradeOutputAmount(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, const TArray<APhysicalItem*>& InputItems) {
    return 0;
}

AActor* UAstroPlayStatics::GetTopmostParentActor(AActor* Component) {
    return NULL;
}

UPrimitiveComponent* UAstroPlayStatics::GetSimulatingParent(USceneComponent* Component) {
    return NULL;
}

UPrimitiveComponent* UAstroPlayStatics::GetSimulatingAttachParent(USceneComponent* Component) {
    return NULL;
}

FVector UAstroPlayStatics::GetRopeInterpNormal(const FVector& Start, const FVector& StartNormal, const FVector& End, const FVector& EndNormal, float NormalScale, float Alpha) {
    return FVector{};
}

FVector UAstroPlayStatics::GetRopeInterpLocation(const FVector& Start, const FVector& StartNormal, const FVector& End, const FVector& EndNormal, float NormalScale, float Alpha) {
    return FVector{};
}

TArray<TSubclassOf<UItemType>> UAstroPlayStatics::GetPossibleOutputTypes(TSubclassOf<UItemType> InputItemType) {
    return TArray<TSubclassOf<UItemType>>();
}

TArray<TSubclassOf<UItemType>> UAstroPlayStatics::GetPossibleInputTypes() {
    return TArray<TSubclassOf<UItemType>>();
}

APlayController* UAstroPlayStatics::GetPlayController(const UObject* WorldContextObject, int32 Index) {
    return NULL;
}

bool UAstroPlayStatics::GetNavpoint(FGuid NavpointID, FNavpoint& outNavpoint) {
    return false;
}

FVector UAstroPlayStatics::GetMoveDirection3D(APlayerController* Controller, AActor* Actor, const FVector ControlDirection) {
    return FVector{};
}

FVector UAstroPlayStatics::GetMoveDirection(APlayerController* Controller, AActor* Actor, const FVector2D ControlDirection) {
    return FVector{};
}

bool UAstroPlayStatics::GetMinimumDiscreteTradeRatioBetweenItems(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, int32& OutDiscreteInputRatioTerm, int32& OutDiscreteOutputRatioTerm) {
    return false;
}

APlayController* UAstroPlayStatics::GetLocalPlayController(const UObject* WorldContextObject) {
    return NULL;
}

AAstroCharacter* UAstroPlayStatics::GetLocalAstroCharacter(const UObject* WorldContextObject) {
    return NULL;
}

UItemType* UAstroPlayStatics::GetItemTypeDefault(TSubclassOf<UItemType> Type) {
    return NULL;
}

APlayerController* UAstroPlayStatics::GetCurrentInputController() {
    return NULL;
}

UControlSymbol* UAstroPlayStatics::GetControlSymbolDefault(TSubclassOf<UControlSymbol> Type) {
    return NULL;
}

TArray<APhysicalItem*> UAstroPlayStatics::GetConsumedInputItemsForTradeOutput(TSubclassOf<UItemType> InputItemType, TSubclassOf<UItemType> OutputItemType, int32 TargetOutputAmount, const TArray<APhysicalItem*>& InputItems) {
    return TArray<APhysicalItem*>();
}

TArray<APlayController*> UAstroPlayStatics::GetAllPlayControllers(UObject* WorldContextObject) {
    return TArray<APlayController*>();
}

FVoxelMaterial UAstroPlayStatics::DowncastTerrainMaterial(UObject* WorldContextObject, const FVector& Location) {
    return FVoxelMaterial{};
}

void UAstroPlayStatics::ClickActor(AActor* Actor) {
}

void UAstroPlayStatics::Click(UPrimitiveComponent* Primitive) {
}

FGuid UAstroPlayStatics::AuthorityTrackNavpointOnCurrentPlanet(const FNavpoint& newNavpoint) {
    return FGuid{};
}

void UAstroPlayStatics::AuthoritySetNavpointOverrideIconOnCurrentPlanet(FGuid NavpointID, UTexture* Icon) {
}

void UAstroPlayStatics::AuthoritySetNavpointOverrideColorOnCurrentPlanet(FGuid NavpointID, FLinearColor Color) {
}

void UAstroPlayStatics::AuthoritySetNavpointEnabledOnCurrentPlanet(FGuid NavpointID, bool IsEnabled) {
}

void UAstroPlayStatics::AuthorityRemoveNavpointOnCurrentPlanet(FGuid NavpointID) {
}

FGuid UAstroPlayStatics::AuthorityPushNavpointGroupSettingOnGivenPlanet(AAstroPlanet* Planet, ENavpointGroup Group, bool IsEnabled) {
    return FGuid{};
}

FGuid UAstroPlayStatics::AuthorityPushNavpointGroupSettingOnCurrentPlanet(AActor* planetContextObject, ENavpointGroup Group, bool IsEnabled) {
    return FGuid{};
}

void UAstroPlayStatics::AuthorityPopNavpointGroupSetting(FGuid settingID) {
}

void UAstroPlayStatics::AddComponentForceAtLocation(USceneComponent* Component, const FVector& force, const FVector& Location) {
}

UAstroPlayStatics::UAstroPlayStatics() {
}

