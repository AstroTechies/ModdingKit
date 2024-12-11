#include "IconRigNative.h"

AIconRigNative::AIconRigNative(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PrimaryMesh = NULL;
    this->SecondaryMesh = NULL;
    this->TertiaryMesh = NULL;
    this->SecondaryIconLocation = NULL;
    this->SecondaryDecal = NULL;
    this->TerrainFunctionDecal = NULL;
    this->DecalMaterialFunction = NULL;
    this->DecalMaterialSecondary = NULL;
    this->IconsLocation = NULL;
    this->AstroIcon = NULL;
    this->BackpackIcon = NULL;
}



