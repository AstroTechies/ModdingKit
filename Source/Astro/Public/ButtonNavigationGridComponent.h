#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ActorComponent -FallbackName=ActorComponent
#include "ButtonNavigationGridComponent.generated.h"

class UButtonComponent;
class UInputComponent;
class APlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UButtonNavigationGridComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint32 InitialSelectedRow;
    
    UPROPERTY(EditAnywhere)
    uint32 InitialSelectedColumn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bAutoClickAndBounceBack: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnalogThreshold;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UButtonComponent*> Buttons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* InputComponent;
    
public:
    UButtonNavigationGridComponent();
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
    UFUNCTION()
    void NavigateUp();
    
    UFUNCTION()
    void NavigateRight();
    
    UFUNCTION()
    void NavigateLeft();
    
    UFUNCTION()
    void NavigateDown();
    
    UFUNCTION()
    void Confirm();
    
    UFUNCTION()
    void AnalogVertical(float Y);
    
    UFUNCTION()
    void AnalogHorizontal(float X);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddButton(UButtonComponent* Button, int32 row, int32 column);
    
};

