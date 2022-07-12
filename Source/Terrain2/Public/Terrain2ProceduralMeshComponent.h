#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=MeshComponent -FallbackName=MeshComponent
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Interface_CollisionDataProvider -FallbackName=Interface_CollisionDataProvider
#include "T2ProcMeshSection.h"
#include "Terrain2ProceduralMeshComponent.generated.h"

class UMaterialInterface;
class UBodySetup;
class UMaterialInstanceDynamic;
class UMaterialRemapTable;

UCLASS(ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TERRAIN2_API UTerrain2ProceduralMeshComponent : public UMeshComponent, public IInterface_CollisionDataProvider {
    GENERATED_BODY()
public:
    UPROPERTY(Instanced)
    UBodySetup* ProcMeshBodySetup;
    
    UPROPERTY(Transient)
    TArray<UMaterialInstanceDynamic*> Materials;
    
    UPROPERTY(Transient)
    UMaterialInterface* DefaultMaterialShadows;
    
    UPROPERTY(Transient)
    UMaterialRemapTable* HQMaterialRemapTable;
    
    UPROPERTY(Transient)
    TArray<FT2ProcMeshSection> ProcMeshSections;
    
    UTerrain2ProceduralMeshComponent();
    
    // Fix for true pure virtual functions not being implemented
};

