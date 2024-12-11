#include "DeformTargetComponent.h"

UDeformTargetComponent::UDeformTargetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

FTransform UDeformTargetComponent::GetDeformTarget(const FVector& sourceLocation) {
    return FTransform{};
}


