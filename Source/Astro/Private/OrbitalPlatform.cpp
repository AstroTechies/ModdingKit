#include "OrbitalPlatform.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ClickableComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "TooltipComponent.h"

AOrbitalPlatform::AOrbitalPlatform(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
    this->bAllowsCreativeFlight = true;
    this->PlatformMesh = (UStaticMeshComponent*)RootComponent;
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->TooltipComponent = CreateDefaultSubobject<UTooltipComponent>(TEXT("ToolTip"));
    this->ClickCollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("ClickCollisionSphere"));
    this->ProxyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProxyMesh"));
    this->ProxyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ProxyRoot"));
    this->ProxyMeshScale = 10.00f;
    this->OrbitalRadius = 30000.00f;
    this->OrbitalDistance = 300000.00f;
    this->REP_OrbitingPlanetIdentifier = EPlanetIdentifier::None;
    this->REP_Stage = 0;
    this->REP_MiniPlanetClass = NULL;
    this->MiniPlanetActorRef = NULL;
    this->PendingDeleteMiniPlanetRef = NULL;
    this->REP_bCloudsEnabled = true;
    this->bHasCreativeFlightEnabled = false;
    this->ClickCollisionSphere->SetupAttachment(ProxyMesh);
    this->ProxyMesh->SetupAttachment(ProxyRoot);
    this->ProxyRoot->SetupAttachment(RootComponent);
}

void AOrbitalPlatform::SetVoxelsVisibility(bool bIsVisible, bool bForceUpdate) {
}

void AOrbitalPlatform::SetPlanetSelection(const bool bInEnable) {
}

void AOrbitalPlatform::SetMeshVisibility(bool bIsVisible) {
}

bool AOrbitalPlatform::RemoveTrueFlatPlatform(ATrueFlatPlatform* inTFP) {
    return false;
}


void AOrbitalPlatform::OnSolarBodyClick(ASolarBody* inSolarBody) {
}

void AOrbitalPlatform::OnRep_StageChanged() {
}

void AOrbitalPlatform::OnRep_OrbitingPlanetUpdated() {
}

void AOrbitalPlatform::OnRep_MiniPlanetClassUpdated() {
}

void AOrbitalPlatform::OnRep_CloudsEnabledUpdated() {
}


void AOrbitalPlatform::OnClickedInSolarView(AActor* TouchedActor, FKey ButtonPressed) {
}

void AOrbitalPlatform::K2_MiniPlanetVFXOpened() {
}

void AOrbitalPlatform::K2_MiniPlanetVFXEnclosed() {
}

TArray<ATrueFlatPlatform*> AOrbitalPlatform::GetTrueFlatPlatfroms() const {
    return TArray<ATrueFlatPlatform*>();
}

FVector AOrbitalPlatform::GetTerrainNormal(const FVector& Location) {
    return FVector{};
}

int32 AOrbitalPlatform::GetCurrentStage() const {
    return 0;
}

void AOrbitalPlatform::AuthorityToggleClouds() {
}

void AOrbitalPlatform::AuthoritySetMiniPlanetClass(TSubclassOf<AMiniPlanet> MiniPlanetClass) {
}

void AOrbitalPlatform::AuthoritySetCreativeFlightEnabled(const bool bInIsEnabled) {
}

void AOrbitalPlatform::AuthoritySetCloudsEnabled(bool bEnabled) {
}

void AOrbitalPlatform::AuthorityMoveOrbitalPlatformToOtherPlanet(const EPlanetIdentifier inPlanetIdentifier) {
}

void AOrbitalPlatform::AuthorityIncrementStage() {
}

void AOrbitalPlatform::AddTrueFlatPlatform(ATrueFlatPlatform* inTFP) {
}

void AOrbitalPlatform::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AOrbitalPlatform, REP_OrbitingPlanetIdentifier);
    DOREPLIFETIME(AOrbitalPlatform, REP_Stage);
    DOREPLIFETIME(AOrbitalPlatform, REP_MiniPlanetClass);
    DOREPLIFETIME(AOrbitalPlatform, TrueFlatPlatforms);
    DOREPLIFETIME(AOrbitalPlatform, REP_bCloudsEnabled);
    DOREPLIFETIME(AOrbitalPlatform, bHasCreativeFlightEnabled);
}


