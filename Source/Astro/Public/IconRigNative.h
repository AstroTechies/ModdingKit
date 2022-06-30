#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IconRigNative.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class UDecalComponent;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API AIconRigNative : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *PrimaryMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *SecondaryMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UStaticMeshComponent *TertiaryMesh;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *SecondaryIconLocation;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UDecalComponent *SecondaryDecal;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    UDecalComponent *TerrainFunctionDecal;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *DecalMaterialFunction;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    UMaterialInstanceDynamic *DecalMaterialSecondary;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *IconsLocation;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *AstroIcon;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *BackpackIcon;

    AIconRigNative();
    UFUNCTION(BlueprintImplementableEvent)
    void DoTeriaryIcons(bool astroVisible, bool backpackVisible, bool astroSeated);
};
