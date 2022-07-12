#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=BodyInstance -FallbackName=BodyInstance
#include "FoliageDestructionInfo.h"
#include "AstroFoliageType.generated.h"

class UStaticMesh;
class AActor;
class UMaterialInterface;

UCLASS(BlueprintType)
class UAstroFoliageType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY()
    FBodyInstance BodyInstance;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSoftObjectPtr<UStaticMesh> m_mesh;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TSubclassOf<AActor> m_replacementClass;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    UClass* ItemType;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FName SoundRTPCName;
    
    UPROPERTY(EditAnywhere)
    FFoliageDestructionInfo FoliageDestructionInfo;
    
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    TArray<UMaterialInterface*> OverrideMaterials;
    
    UAstroFoliageType();
};

