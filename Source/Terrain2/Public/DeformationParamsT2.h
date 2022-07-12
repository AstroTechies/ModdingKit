#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize100 -FallbackName=Vector_NetQuantize100
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantizeNormal -FallbackName=Vector_NetQuantizeNormal
#include "EDeformType.h"
#include "EDeformShape.h"
#include "DeformationParamsT2.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FDeformationParamsT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    TWeakObjectPtr<AActor> Instigator;
    
    UPROPERTY(BlueprintReadWrite)
    FVector_NetQuantize100 Location;
    
    UPROPERTY(BlueprintReadWrite)
    FVector_NetQuantizeNormal Normal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float DeltaTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EDeformType Operation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    EDeformShape Shape;
    
    UPROPERTY()
    uint16 SequenceNumber;
    
    UPROPERTY()
    int16 MaterialIndex;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 HardnessPenetration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    uint8 ForceRemoveDecorators: 1;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
    uint8 CreativeModeNoResourceCollection: 1;
    
    UPROPERTY()
    uint8 bUseAlternatePolygonization: 1;
    
    UPROPERTY(BlueprintReadOnly)
    uint8 bEasyUnbury: 1;
    
    UPROPERTY(BlueprintReadOnly)
    float AutoCreateResourceEfficiency;
    
    TERRAIN2_API FDeformationParamsT2();
};

