#pragma once
#include "CoreMinimal.h"
#include "ObjectSaveRecord.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FObjectSaveRecord {
    GENERATED_BODY()
public:
    UPROPERTY(Transient)
    UObject* RuntimeObject;
    
    UPROPERTY()
    UClass* Class;
    
    UPROPERTY(Transient)
    FString Name;
    
    UPROPERTY()
    uint32 NameIndex;
    
    UPROPERTY()
    uint32 Flags;
    
    UPROPERTY()
    uint32 OuterObjectIndex;
    
    UPROPERTY()
    uint32 CustomDataOffset;
    
    UPROPERTY()
    TArray<uint8> Data;
    
    ASTRO_API FObjectSaveRecord();
};

