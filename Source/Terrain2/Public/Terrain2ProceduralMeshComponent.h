#pragma once
#include "CoreMinimal.h"
#include "Interfaces/Interface_CollisionDataProvider.h"
#include "Components/MeshComponent.h"
#include "T2ProcMeshSection.h"
#include "Terrain2ProceduralMeshComponent.generated.h"

class UBodySetup;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMaterialRemapTable;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class TERRAIN2_API UTerrain2ProceduralMeshComponent : public UMeshComponent, public IInterface_CollisionDataProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBodySetup* ProcMeshBodySetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> Materials;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DefaultMaterialShadows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialRemapTable* HQMaterialRemapTable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FT2ProcMeshSection> ProcMeshSections;
    
    UTerrain2ProceduralMeshComponent(const FObjectInitializer& ObjectInitializer);


    // Fix for true pure virtual functions not being implemented
};

