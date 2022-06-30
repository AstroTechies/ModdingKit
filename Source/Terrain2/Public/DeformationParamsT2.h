#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "EDeformShape.h"
#include "EDeformType.h"
#include "Engine/NetSerialization.h"
#include "DeformationParamsT2.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FDeformationParamsT2 {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Instigator;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize100 Location;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    FVector_NetQuantizeNormal Normal;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float DeltaTime;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    float Scale;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EDeformType Operation;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    EDeformShape Shape;
    
    UPROPERTY()
    uint16 SequenceNumber;
    
    UPROPERTY()
    int16 MaterialIndex;
    
    UPROPERTY(EditDefaultsOnly)
    uint8 HardnessPenetration;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    uint8 ForceRemoveDecorators: 1;
    
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta=(AllowPrivateAccess=true))
    uint8 CreativeModeNoResourceCollection: 1;
    
    UPROPERTY()
    uint8 bUseAlternatePolygonization: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    uint8 bEasyUnbury: 1;
    
    UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess=true))
    float AutoCreateResourceEfficiency;
    
    TERRAIN2_API FDeformationParamsT2();
};

