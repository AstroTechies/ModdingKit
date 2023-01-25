#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ComponentReference -FallbackName=ComponentReference
#include "SnailCrackableActor.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ASnailCrackableActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference ClickableComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference CrackableComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SnailSkeletonComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference TerrariumMeshComponentRef;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentReference SlotsComponentRef;
    
    ASnailCrackableActor();
};

