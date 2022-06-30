#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TetherReplicatedState.h"
#include "TetherEdgeArray.h"
#include "TetherManager.generated.h"

class USceneComponent;
class UTetherPostComponent;

UCLASS(Blueprintable, Blueprintable)
class ATetherManager : public AActor
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(Replicated, Transient)
    FTetherReplicatedState repState;

    UPROPERTY(Transient)
    TMap<USceneComponent *, FTetherEdgeArray> SceneComponentToEdges;

    UPROPERTY(Export, Transient)
    TArray<UTetherPostComponent *> TetherPostComponents;

    UPROPERTY(Export, Transient)
    TArray<UTetherPostComponent *> PlacingTetherPostComponents;

    UPROPERTY(Transient)
    int32 TetherPostUpdateIndex;

public:
    ATetherManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;
};
