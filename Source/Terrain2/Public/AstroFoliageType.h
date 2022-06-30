#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "PhysicsEngine/BodyInstance.h"
#include "FoliageDestructionInfo.h"
#include "AstroFoliageType.generated.h"

class UStaticMesh;
class AActor;
class UMaterialInterface;

UCLASS(Blueprintable, BlueprintType)
class UAstroFoliageType : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY()
    FBodyInstance BodyInstance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSoftObjectPtr<UStaticMesh> m_mesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSubclassOf<AActor> m_replacementClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UClass *ItemType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName SoundRTPCName;

    UPROPERTY(EditAnywhere)
    FFoliageDestructionInfo FoliageDestructionInfo;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<UMaterialInterface *> OverrideMaterials;

    UAstroFoliageType();
};
