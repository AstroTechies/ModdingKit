#pragma once
#include "CoreMinimal.h"
#include "AstroCustomizationItem.h"
#include "EEmoteType.h"
#include "Templates/SubclassOf.h"
#include "AstroEmoteDefinition.generated.h"

class UAnimMontage;
class UAstroPlayMontageAction;
class USkeletalMesh;

UCLASS(Blueprintable)
class ASTRO_API UAstroEmoteDefinition : public UAstroCustomizationItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEmoteType EmoteType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAstroPlayMontageAction> EmoteActionTypeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UAnimMontage> DefaultMontage;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<USkeletalMesh>, TSoftObjectPtr<UAnimMontage>> SuitSpecificMontages;
    
public:
    UAstroEmoteDefinition();

};

