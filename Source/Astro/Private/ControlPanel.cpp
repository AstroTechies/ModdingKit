#include "ControlPanel.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ClickableComponent.h"
#include "CrackableActorComponent.h"
#include "Net/UnrealNetwork.h"

AControlPanel::AControlPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bReplicates = true;
//    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
//    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->RootComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
    this->RedirectOwnerInteractions = true;
    this->SkeletalMesh = (USkeletalMeshComponent*)RootComponent;
    this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    this->ControlPanelLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("ControlPanelLight"));
    this->CrackableActorComponent = CreateDefaultSubobject<UCrackableActorComponent>(TEXT("CrackableActor"));
    this->ClickableComponent = CreateDefaultSubobject<UClickableComponent>(TEXT("clickable"));
    this->ControlledActor = NULL;
    this->CameraContext = NULL;
    this->FallbackInputComponent = NULL;
    this->FirstNavigationRepeatDelay = 0.50f;
    this->NavigationRepetitionInterval = 0.15f;
    this->AnalogStickNavigationThreshold = 0.50f;
    this->bAutoOptimizeHierarchy = false;
    this->ControlPanelLight->SetupAttachment(RootComponent);
    this->StaticMesh->SetupAttachment(RootComponent);
}


void AControlPanel::OnSecondaryButtonPressed() {
}

void AControlPanel::OnRep_ControlledActor() {
}

void AControlPanel::OnOwnerItemPickedUpOrUnslotted(bool bUnused) {
}

void AControlPanel::OnNavigationComponentClicked(UPrimitiveComponent* navigationComponent, FKey ButtonPressed) {
}

void AControlPanel::OnNavigateUpRepeat() {
}

void AControlPanel::OnNavigateUpDown(float AxisValue) {
}


void AControlPanel::OnNavigateUp() {
}

void AControlPanel::OnNavigateRightRepeat() {
}


void AControlPanel::OnNavigateRight() {
}

void AControlPanel::OnNavigateLeftRight(float AxisValue) {
}

void AControlPanel::OnNavigateLeftRepeat() {
}


void AControlPanel::OnNavigateLeft() {
}

void AControlPanel::OnNavigateDownRepeat() {
}


void AControlPanel::OnNavigateDown() {
}

void AControlPanel::OnCrackableActorComponentExaminableChanged() {
}



void AControlPanel::OnConfirm() {
}


void AControlPanel::OnCancel() {
}

bool AControlPanel::IsLocallyControlled() const {
    return false;
}

bool AControlPanel::GetCracked() const {
    return false;
}

void AControlPanel::FullyCrackedOrClosed(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked) {
}

void AControlPanel::CrackedChanged(UCrackableActorComponent* NewCrackableActorComponent, bool bIsCracked) {
}

void AControlPanel::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AControlPanel, ControlledActor);
}


