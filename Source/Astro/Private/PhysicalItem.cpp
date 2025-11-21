#include "PhysicalItem.h"
#include "Components/StaticMeshComponent.h"
#include "ActorEntityLinkComponent.h"
#include "ClickableComponent.h"
#include "ItemComponent.h"
#include "Net/UnrealNetwork.h"
#include "ProceduralStateComponent.h"
#include "SlotsComponent.h"
#include "Templates/SubclassOf.h"
#include "TerrainPhysicsComponent.h"
#include "TooltipComponent.h"
#include "WorldGravity.h"

APhysicalItem::APhysicalItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
//    this->bSaveGameRelevant = true;
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
    this->ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("Item"));
    this->EntityLinkComponent = CreateDefaultSubobject<UActorEntityLinkComponent>(TEXT("EntityLinkComponent"));
    this->terrainComponent = CreateDefaultSubobject<UTerrainPhysicsComponent>(TEXT("Terrain Physics"));
    this->PlaceholderPrimitive = NULL;
    this->PlaceholderMesh = NULL;
    this->StaticMeshComponent = (UStaticMeshComponent*)RootComponent;
    this->GravityComponent = CreateDefaultSubobject<UWorldGravity>(TEXT("Gravity"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("ItemClickableComponent"));
    this->SlotsComponent = CreateDefaultSubobject<USlotsComponent>(TEXT("SlotsComponent"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("TooltipComponent"));
    this->ProceduralState = CreateDefaultSubobject<UProceduralStateComponent>(TEXT("ProceduralStateComponent"));
    // Can this item be directly attached to the body of an object (like packagers and dynamite do)?
    this->SlotQueryAllowBodyPlacement = false;
    this->OffsetOddTiers = false;
    // no idea
    this->HoverHeight = 110.00f;
    this->IndicatorUseAnimInstance = false;
    this->WeldAsChild = true;
    this->UseHoverForward = true;
    // no idea
    this->IgnoreBodySlotForHover = false;
    // The height of the printer, overrides the default determined height value if defined
    this->PrinterHeight = 0.00f;
    // The tier of the object. 1 = T1, 2 = T2, etc. Controls fallback slot size, default package size, as well as walking speed
    this->ToolMoveTier = 1;
    this->SlotTierSpawnOverride = 0;
    this->PlacementSnapToGroundHeight = 0.00f;
    // Can this item be picked up and moved around with the cursor?
    this->IsMovable = true;
    this->AlwaysMovePhysical = false;
    this->ItemWorldScale = 1.00f;
    this->SlotScale = 1.00f;
    this->IndicatorScale = 1.00f;
    this->bDestroyWhenDrained = false;
    this->PrintSpeedOverride = 0.00f;
    this->MostRecentNetOwner = NULL;
    // Can this item be slotted?
    this->IsUnslottable = false;
    this->bIsAttachedToTerrain = false;
}

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

void APhysicalItem::SetIsAttachedToTerrain(bool isAttachedToTerrain) {
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

bool APhysicalItem::IsFakeTerrainObject_Implementation() {
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

// The height of the printer, overrides the default determined height value if defined
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

// Can this item be slotted?
void APhysicalItem::AuthoritySetIsUnslottable(bool bIsUnslottable) {
}

bool APhysicalItem::AcceptsFakeTerrainObjectsAsTerrain_Implementation() {
    return false;
}

void APhysicalItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APhysicalItem, EmplacementData);
    // Can this item be slotted?
    DOREPLIFETIME(APhysicalItem, IsUnslottable);
    DOREPLIFETIME(APhysicalItem, ReplicatedState);
}


