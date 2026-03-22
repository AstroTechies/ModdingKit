#include "DeformationParamsT2.h"

FDeformationParamsT2::FDeformationParamsT2() {
    this->DeltaTime = 0.00f;
    this->Intensity = 0.00f;
    this->Scale = 0.00f;
    this->Operation = EDeformType::Subtract;
    this->Shape = EDeformShape::Sphere;
    this->SequenceNumber = 0;
    this->MaterialIndex = 0;
    this->HardnessPenetration = 0;
    this->ForceRemoveDecorators = false;
    this->CreativeModeNoResourceCollection = false;
    this->bUseAlternatePolygonization = false;
    this->bEasyUnbury = false;
    this->AutoCreateResourceEfficiency = 0.00f;
}

