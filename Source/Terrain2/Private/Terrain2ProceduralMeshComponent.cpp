#include "Terrain2ProceduralMeshComponent.h"

UTerrain2ProceduralMeshComponent::UTerrain2ProceduralMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProcMeshBodySetup = NULL;
    this->DefaultMaterialShadows = NULL;
    this->HQMaterialRemapTable = NULL;
}


