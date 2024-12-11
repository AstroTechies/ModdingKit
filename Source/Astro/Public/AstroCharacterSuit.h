#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationItem.h"
#include "Templates/SubclassOf.h"
#include "AstroCharacterSuit.generated.h"

class UAnimInstance;
class UAnimMontage;
class USkeletalMesh;

UCLASS(Blueprintable)
class ASTRO_API UAstroCharacterSuit : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> AnimationBlueprintType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> TitleDummyAnimationBlueprintType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimMontage> PointMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SuitAudioType;
    
    UAstroCharacterSuit();

};

