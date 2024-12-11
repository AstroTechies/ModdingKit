#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BitfieldBitValue.h"
#include "PackedParameterValue.h"
#include "AstroMaterialStatics.generated.h"

class UMaterialInstanceDynamic;

UCLASS(Blueprintable)
class ASTRO_API UAstroMaterialStatics : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAstroMaterialStatics();

    UFUNCTION(BlueprintCallable)
    static void ToggleBitfieldParameterBits(UMaterialInstanceDynamic* Mid, FName ParameterName, const TArray<int32>& BitIndices);
    
    UFUNCTION(BlueprintCallable)
    static void ToggleBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex);
    
    UFUNCTION(BlueprintCallable)
    static void SetPackedParameterValues(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 PackedValueBitSize, const TArray<FPackedParameterValue>& PackedParameterValues);
    
    UFUNCTION(BlueprintCallable)
    static void SetPackedParameterValue(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 PackedSlotIndex, int32 PackedValueBitSize, int32 PackedValue);
    
    UFUNCTION(BlueprintCallable)
    static void SetBitfieldParamterBits(UMaterialInstanceDynamic* Mid, FName ParameterName, const TArray<FBitfieldBitValue>& BitValues);
    
    UFUNCTION(BlueprintCallable)
    static void SetBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex, bool BitValue);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBitfieldParameterBit(UMaterialInstanceDynamic* Mid, FName ParameterName, int32 BitIndex);
    
};

