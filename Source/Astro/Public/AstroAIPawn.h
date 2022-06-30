#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UObject/NoExportTypes.h"
#include "AstroAIPawn.generated.h"

class USceneComponent;
class UAstroActionComponent;

UCLASS(Blueprintable, Blueprintable)
class AAstroAIPawn : public APawn
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *TargetingOriginNode;

    UPROPERTY(BlueprintReadWrite, Export, meta = (AllowPrivateAccess = true))
    USceneComponent *AttackOriginNode;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    FRotator AttackRotator;

    UPROPERTY(EditDefaultsOnly)
    bool CalculateAttackRotatorOnlyInZ;

    UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = true))
    bool IsWarning;

protected:
    UPROPERTY(BlueprintReadWrite, Export, VisibleDefaultsOnly, meta = (AllowPrivateAccess = true))
    UAstroActionComponent *ActionComponent;

public:
    AAstroAIPawn();
};
