#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DynamicHeightChangeDelegateDelegate.h"
#include "DynamicHeightEvaluationComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UDynamicHeightEvaluationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDynamicHeightChangeDelegate OnDynamicHeightChangeDelegate;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_OnCurrentDynamicHeightChanged, meta=(AllowPrivateAccess=true))
    float CurrentDynamicHeight;
    
public:
    UDynamicHeightEvaluationComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetCurrentDynamicHeight(float Height);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_OnCurrentDynamicHeightChanged();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentDynamicHeight();
    
};

