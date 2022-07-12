#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "ResourceType.generated.h"

class UResourceType;

UCLASS(Blueprintable)
class ASTRO_API UResourceType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ResourceColor;
    
    UResourceType();
    UFUNCTION(BlueprintPure)
    static UResourceType* ResourceTypeDefault(TSubclassOf<UResourceType> Class);
    
};

