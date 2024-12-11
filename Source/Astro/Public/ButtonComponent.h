#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "InputCoreTypes.h"
#include "ButtonShape.h"
#include "ComponentOnButtonClickedDelegate.h"
#include "ButtonComponent.generated.h"

class UAnimationAsset;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneComponent;
class USkeletalMesh;
class UStaticMesh;
class UTextRenderComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ASTRO_API UButtonComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* IconMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* IconMesh_Static;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationAsset* IconAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SpinIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseToolTip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ToolTipText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoServerClick;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ClientEnableAllowed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FComponentOnButtonClicked OnButtonClicked;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ButtonShape Shape;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* shellComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* collisionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ToolTipScene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* TextRenderer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ShellMaterial;
    
public:
    UButtonComponent(const FObjectInitializer& ObjectInitializer);

    UFUNCTION(BlueprintCallable)
    void SetShellComponent(UPrimitiveComponent* NewShellComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetFlashing(bool Flashing);
    
    UFUNCTION(BlueprintCallable)
    void SetCollisionComponent(UPrimitiveComponent* NewCollisionComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetAllShellMaterials(UMaterialInterface* Material);
    
    UFUNCTION(BlueprintCallable)
    void OnShellReleased(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    void OnShellClick(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    void OnEndHover(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable)
    void OnClick(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginHover(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEnabled();
    
    UFUNCTION(BlueprintCallable)
    void Enable(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* CreateShellDynamicMaterialInstance(int32 MaterialIndex, UMaterialInterface* Material);
    
};

