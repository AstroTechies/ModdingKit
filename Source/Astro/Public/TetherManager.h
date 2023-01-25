#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TetherEdgeArray.h"
#include "TetherReplicatedState.h"
#include "TetherManager.generated.h"

class USceneComponent;
class UTetherPostComponent;

UCLASS(Blueprintable)
class ATetherManager : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FTetherReplicatedState repState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<USceneComponent*, FTetherEdgeArray> SceneComponentToEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTetherPostComponent*> TetherPostComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTetherPostComponent*> PlacingTetherPostComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 TetherPostUpdateIndex;
    
public:
    ATetherManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
};

