#pragma once
#include "CoreMinimal.h"
#include "ObjectSaveRecord.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FObjectSaveRecord {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObject* RuntimeObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Class;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FString Name;
    
    UPROPERTY(EditAnywhere)
    uint32 NameIndex;
    
    UPROPERTY(EditAnywhere)
    uint32 Flags;
    
    UPROPERTY(EditAnywhere)
    uint32 OuterObjectIndex;
    
    UPROPERTY(EditAnywhere)
    uint32 CustomDataOffset;
    
    UPROPERTY(EditAnywhere)
    TArray<uint8> Data;
    
    ASTRO_API FObjectSaveRecord();
};

