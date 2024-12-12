#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ButtonNavigationGridComponent.generated.h"

class APlayerController;
class UButtonComponent;
class UInputComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UButtonNavigationGridComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 InitialSelectedRow;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 InitialSelectedColumn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoClickAndBounceBack: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnalogThreshold;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UButtonComponent*> Buttons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* InputComponent;
    
public:
    UButtonNavigationGridComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetSelectedGridCell(int32 row, int32 column);
    
    UFUNCTION(BlueprintCallable)
    void SetSelectedButton(UButtonComponent* Button);
    
    UFUNCTION(BlueprintCallable)
    void ResetGrid(int32 rows, int32 columns);
    
    UFUNCTION(BlueprintCallable)
    void PushInputFocus(APlayerController* Controller);
    
    UFUNCTION(BlueprintCallable)
    void PopInputFocus(APlayerController* Controller);
    
private:
    UFUNCTION(BlueprintCallable)
    void NavigateUp();
    
    UFUNCTION(BlueprintCallable)
    void NavigateRight();
    
    UFUNCTION(BlueprintCallable)
    void NavigateLeft();
    
    UFUNCTION(BlueprintCallable)
    void NavigateDown();
    
    UFUNCTION(BlueprintCallable)
    void Confirm();
    
    UFUNCTION(BlueprintCallable)
    void AnalogVertical(float Y);
    
    UFUNCTION(BlueprintCallable)
    void AnalogHorizontal(float X);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent* Button, int32 row, int32 column);
    
};

