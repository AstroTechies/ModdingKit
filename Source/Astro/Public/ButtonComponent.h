#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "ButtonShape.h"
#include "ComponentOnButtonClickedDelegate.h"
#include "InputCoreTypes.h"
#include "ButtonComponent.generated.h"

class UMaterialInstanceDynamic;
class UStaticMesh;
class USkeletalMesh;
class UAnimationAsset;
class UTextRenderComponent;
class USceneComponent;
class UMaterialInterface;

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class ASTRO_API UButtonComponent : public UPrimitiveComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    USkeletalMesh *IconMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UStaticMesh *IconMesh_Static;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UAnimationAsset *IconAnimation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool SpinIcon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool UseToolTip;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FString ToolTipText;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool DoServerClick;

    UPROPERTY(EditAnywhere)
    bool ClientEnableAllowed;

    UPROPERTY(BlueprintAssignable)
    FComponentOnButtonClicked OnButtonClicked;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    ButtonShape Shape;

private:
    UPROPERTY(Export, Transient)
    UPrimitiveComponent *shellComponent;

    UPROPERTY(Export, Transient)
    UPrimitiveComponent *collisionComponent;

    UPROPERTY(Export, Transient)
    UPrimitiveComponent *Icon;

    UPROPERTY(Export, Transient)
    USceneComponent *ToolTipScene;

    UPROPERTY(Export, Transient)
    UTextRenderComponent *TextRenderer;

    UPROPERTY(Transient)
    UMaterialInstanceDynamic *ShellMaterial;

public:
    UButtonComponent();
    UFUNCTION(BlueprintCallable)
    void SetShellComponent(UPrimitiveComponent *NewShellComponent);

    UFUNCTION(BlueprintCallable)
    void SetFlashing(bool Flashing);

    UFUNCTION(BlueprintCallable)
    void SetCollisionComponent(UPrimitiveComponent *NewCollisionComponent);

    UFUNCTION(BlueprintCallable)
    void SetAllShellMaterials(UMaterialInterface *Material);

    UFUNCTION()
    void OnShellReleased(UPrimitiveComponent *Component, FKey ButtonPressed);

    UFUNCTION()
    void OnShellClick(UPrimitiveComponent *Component, FKey ButtonPressed);

    UFUNCTION()
    void OnEndHover(UPrimitiveComponent *Component);

    UFUNCTION()
    void OnClick(UPrimitiveComponent *Component, FKey ButtonPressed);

    UFUNCTION()
    void OnBeginHover(UPrimitiveComponent *Component);

    UFUNCTION(BlueprintPure)
    bool IsEnabled();

    UFUNCTION(BlueprintCallable)
    void Enable(bool Enabled);

    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic *CreateShellDynamicMaterialInstance(int32 MaterialIndex, UMaterialInterface *Material);
};
