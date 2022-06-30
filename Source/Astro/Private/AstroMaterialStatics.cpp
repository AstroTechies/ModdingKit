#include "AstroMaterialStatics.h"

class UMaterialInstanceDynamic;

void UAstroMaterialStatics::ToggleBitfieldParameterBits(UMaterialInstanceDynamic* Mid, FName ParameterName, const TArray<int32>& BitIndices) {
}

void UAstroMaterialStatics::ToggleBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex) {
}

void UAstroMaterialStatics::SetPackedParameterValues(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 PackedValueBitSize, const TArray<FPackedParameterValue>& PackedParameterValues) {
}

void UAstroMaterialStatics::SetPackedParameterValue(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 PackedSlotIndex, int32 PackedValueBitSize, int32 PackedValue) {
}

void UAstroMaterialStatics::SetBitfieldParamterBits(UMaterialInstanceDynamic* Mid, FName ParameterName, const TArray<FBitfieldBitValue>& BitValues) {
}

void UAstroMaterialStatics::SetBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex, bool BitValue) {
}

bool UAstroMaterialStatics::GetBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex) {
    return false;
}

UAstroMaterialStatics::UAstroMaterialStatics() {
}

