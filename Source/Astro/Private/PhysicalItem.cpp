#include "PhysicalItem.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "ClickableComponent.h"
#include "TerrainPhysicsComponent.h"
#include "ItemComponent.h"
#include "WorldGravity.h"
#include "ActorEntityLinkComponent.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=StaticMeshComponent -FallbackName=StaticMeshComponent
#include "SlotsComponent.h"
#include "TooltipComponent.h"
#include "ProceduralStateComponent.h"

class UPrimitiveComponent;
class USceneComponent;
class APawn;
class UItemType;
class APhysicalItem;
class UChildSlotComponent;

void APhysicalItem::StartItemInWorld() {
}


bool APhysicalItem::ShouldPickUp_Implementation(UPrimitiveComponent* PrimComponent) {
    return false;
}

void APhysicalItem::SetWorldPhysics() {
}

void APhysicalItem::SetPuppetPhysics() {
}

void APhysicalItem::SetPhysicsState(EPhysicalItemMotionState State, USceneComponent* AttachParent, const FName& SocketName, bool weld) {
}

void APhysicalItem::SetNonSimulatingPhysics() {
}

void APhysicalItem::SetIndicatorPhysics() {
}

void APhysicalItem::SetAttachPhysics(USceneComponent* Component, const FName& SocketName, bool DeWeld) {
}

void APhysicalItem::ServerTakePossession_Implementation(APawn* controllingPawn, bool PhysicalMovement, bool PartOfSwap) {
}
bool APhysicalItem::ServerTakePossession_Validate(APawn* controllingPawn, bool PhysicalMovement, bool PartOfSwap) {
    return true;
}

void APhysicalItem::ServerSlotSetItem_Implementation(FSlotReference ItemSlot, int32 SubslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool FromTool, bool SlottedDuringInitialization, bool PartOfSwap, bool skipBundling, bool skipTransformUpdate) {
}
bool APhysicalItem::ServerSlotSetItem_Validate(FSlotReference ItemSlot, int32 SubslotIndex, FSlotReference sourceTransitionSlot, bool useSourceTransform, bool FromTool, bool SlottedDuringInitialization, bool PartOfSwap, bool skipBundling, bool skipTransformUpdate) {
    return true;
}

void APhysicalItem::ServerSlotReleaseItem_Implementation(bool NewOwner, bool FromTool, float RandomForce, bool PartOfSwap) {
}
bool APhysicalItem::ServerSlotReleaseItem_Validate(bool NewOwner, bool FromTool, float RandomForce, bool PartOfSwap) {
    return true;
}

void APhysicalItem::ServerSlotEmplaceItem_Implementation(FSlotReference Slot, int32 SubslotIndex, bool SnapTo, bool weld) {
}
bool APhysicalItem::ServerSlotEmplaceItem_Validate(FSlotReference Slot, int32 SubslotIndex, bool SnapTo, bool weld) {
    return true;
}

void APhysicalItem::ServerSetSlotCardinalDirection_Implementation(uint8 Direction) {
}
bool APhysicalItem::ServerSetSlotCardinalDirection_Validate(uint8 Direction) {
    return true;
}

void APhysicalItem::ServerReleasePossession_Implementation(UPrimitiveComponent* HitComponent, bool NewTerrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
}
bool APhysicalItem::ServerReleasePossession_Validate(UPrimitiveComponent* HitComponent, bool NewTerrainComponent, FVector HitLocation, FVector_NetQuantizeNormal HitNormal) {
    return true;
}

void APhysicalItem::ServerMove_Implementation(FVector_NetQuantize100 clientLoc, float Scale, uint32 clientRot, uint8 clientRoll) {
}
bool APhysicalItem::ServerMove_Validate(FVector_NetQuantize100 clientLoc, float Scale, uint32 clientRot, uint8 clientRoll) {
    return true;
}


FTransform APhysicalItem::PlacementTransform_Implementation(const FHitResult& Hit) {
    return FTransform{};
}


void APhysicalItem::PickUpFromWorld(bool PhysicalMovement) {
}


void APhysicalItem::OnRep_ItemState() {
}

void APhysicalItem::OnRep_EmplacementData() {
}

void APhysicalItem::OnPostDrained() {
}

void APhysicalItem::MulticastSetFullyEmplaced_Implementation(FSlotReference Slot, int32 SubslotIndex) {
}

void APhysicalItem::MulticastReleasedFromSlot_Implementation(bool FromTool, bool NewOwner) {
}

void APhysicalItem::MulticastPickedUpFromWorld_Implementation(bool PhysicalMovement) {
}

void APhysicalItem::MulticastDroppedInWorld_Implementation(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal) {
}

bool APhysicalItem::Movable_Implementation(int32 ToolTier) {
    return false;
}

bool APhysicalItem::IsLarge_Implementation() {
    return false;
}

void APhysicalItem::HandleIsBuriedChanged(UTerrainPhysicsComponent* terrainComp) {
}

int32 APhysicalItem::GetSubSlotIndex() const {
    return 0;
}

TSubclassOf<UItemType> APhysicalItem::GetStoredSubItemTypeClass() const {
    return NULL;
}

UItemType* APhysicalItem::GetStoredSubItemTypeCDO() const {
    return NULL;
}

float APhysicalItem::GetPrinterHeight() const {
    return 0.0f;
}

int32 APhysicalItem::GetPickupToolTier() {
    return 0;
}

APhysicalItem* APhysicalItem::GetPickupItemDefault() {
    return NULL;
}

EPhysicalItemMotionState APhysicalItem::GetMotionState() const {
    return EPhysicalItemMotionState::Simulating;
}

TSubclassOf<UItemType> APhysicalItem::GetLiteralItemTypeClass() const {
    return NULL;
}

UItemType* APhysicalItem::GetLiteralItemTypeCDO() const {
    return NULL;
}

float APhysicalItem::GetItemTypeDefaultScale(TSubclassOf<APhysicalItem> Type) {
    return 0.0f;
}

FText APhysicalItem::GetItemName() const {
    return FText::GetEmpty();
}

UWorldGravity* APhysicalItem::GetGravity() {
    return NULL;
}

TSubclassOf<UItemType> APhysicalItem::GetFunctionalItemTypeClass() const {
    return NULL;
}

UItemType* APhysicalItem::GetFunctionalItemTypeCDO() const {
    return NULL;
}

UChildSlotComponent* APhysicalItem::GetBodySlotLegacy_Implementation() const {
    return NULL;
}

FSlotReference APhysicalItem::GetBodySlot() const {
    return FSlotReference{};
}

FTransform APhysicalItem::GetBaseLocation() {
    return FTransform{};
}


void APhysicalItem::DropInWorld(UPrimitiveComponent* Component, bool NewTerrainComponent, const FVector& Point, const FVector& Normal) {
}

bool APhysicalItem::CanNeverBeSlotted() const {
    return false;
}

void APhysicalItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APhysicalItem, EmplacementData);
    DOREPLIFETIME(APhysicalItem, ReplicatedState);
}

APhysicalItem::APhysicalItem() {
    this->ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Item"));
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLinkComponent"));
    this->terrainComponent = CreateDefaultSubobject<UTerrainPhysicsComponent>(TEXT("Terrain Physics"));
    this->PlaceholderPrimitive = NULL;
    this->StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
    this->GravityComponent = CreateDefaultSubobject<UWorldGravity>(TEXT("Gravity"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("ItemClickableComponent"));
    this->SlotsComponent = CreateDefaultSubobject<USlotsComponent>(TEXT("SlotsComponent"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("TooltipComponent"));
    this->ProceduralState = CreateDefaultSubobject<UProceduralStateComponent>(TEXT("ProceduralStateComponent"));
    this->SlotQueryAllowBodyPlacement = false;
    this->OffsetOddTiers = false;
    this->HoverHeight = 110.00f;
    this->IndicatorUseAnimInstance = false;
    this->WeldAsChild = true;
    this->UseHoverForward = true;
    this->IgnoreBodySlotForHover = false;
    this->PrinterHeight = 0.00f;
    this->ToolMoveTier = 1;
    this->PlacementSnapToGroundHeight = 0.00f;
    this->IsMovable = true;
    this->AlwaysMovePhysical = false;
    this->ItemWorldScale = 1.00f;
    this->SlotScale = 1.00f;
    this->bDestroyWhenDrained = false;
    this->MostRecentNetOwner = NULL;
    this->IsUnslottable = false;
    this->bIsAttachedToTerrain = false;
}

