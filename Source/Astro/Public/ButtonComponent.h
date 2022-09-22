#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=PrimitiveComponent -FallbackName=PrimitiveComponent
#include "ComponentOnButtonClickedDelegate.h"
#include "ButtonShape.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "ButtonComponent.generated.h"

class UTextRenderComponent;
class UStaticMesh;
class USkeletalMesh;
class UAnimationAsset;
class USceneComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;

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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* shellComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* collisionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* ToolTipScene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* TextRenderer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* ShellMaterial;
    
public:
    UButtonComponent();
    UFUNCTION(BlueprintCallable)
    void SetShellComponent(UPrimitiveComponent* NewShellComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetFlashing(bool Flashing);
    
    UFUNCTION(BlueprintCallable)
    void SetCollisionComponent(UPrimitiveComponent* NewCollisionComponent);
    
    UFUNCTION(BlueprintCallable)
    void SetAllShellMaterials(UMaterialInterface* Material);
    
    UFUNCTION()
    void OnShellReleased(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION()
    void OnShellClick(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION()
    void OnEndHover(UPrimitiveComponent* Component);
    
    UFUNCTION()
    void OnClick(UPrimitiveComponent* Component, FKey ButtonPressed);
    
    UFUNCTION()
    void OnBeginHover(UPrimitiveComponent* Component);
    
    UFUNCTION(BlueprintPure)
    bool IsEnabled();
    
    UFUNCTION(BlueprintCallable)
    void Enable(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    UMaterialInstanceDynamic* CreateShellDynamicMaterialInstance(int32 MaterialIndex, UMaterialInterface* Material);
    
};

