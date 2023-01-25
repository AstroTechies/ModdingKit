#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "Templates/SubclassOf.h"
#include "ResourceType.generated.h"

class UResourceType;

UCLASS(Blueprintable)
class ASTRO_API UResourceType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor ResourceColor;
    
    UResourceType();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UResourceType* ResourceTypeDefault(TSubclassOf<UResourceType> Class);
    
};

