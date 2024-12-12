#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
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

