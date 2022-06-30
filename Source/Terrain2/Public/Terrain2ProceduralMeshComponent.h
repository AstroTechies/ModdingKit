#pragma once
#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "Interfaces/Interface_CollisionDataProvider.h"
#include "T2ProcMeshSection.h"
#include "Terrain2ProceduralMeshComponent.generated.h"

class UMaterialRemapTable;
class UMaterialInstanceDynamic;
class UBodySetup;
class UMaterialInterface;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class TERRAIN2_API UTerrain2ProceduralMeshComponent : public UMeshComponent, public IInterface_CollisionDataProvider
{
    GENERATED_BODY()
public:
    UPROPERTY(Instanced)
    UBodySetup *ProcMeshBodySetup;

    UPROPERTY(Transient)
    TArray<UMaterialInstanceDynamic *> Materials;

    UPROPERTY(Transient)
    UMaterialInterface *DefaultMaterialShadows;

    UPROPERTY(Transient)
    UMaterialRemapTable *HQMaterialRemapTable;

    UPROPERTY(Transient)
    TArray<FT2ProcMeshSection> ProcMeshSections;

    UTerrain2ProceduralMeshComponent();

    // Fix for true pure virtual functions not being implemented
};
