#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "ResourceType.generated.h"

class UResourceType;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UResourceType : public UObject
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FLinearColor ResourceColor;

    UResourceType();
    UFUNCTION(BlueprintPure)
    static UResourceType *ResourceTypeDefault(TSubclassOf<UResourceType> Class);
};
