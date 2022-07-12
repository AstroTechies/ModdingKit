#pragma once
#include "CoreMinimal.h"
#include "EAstroColor.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=LinearColor -FallbackName=LinearColor
#include "AstroColorDatabase.generated.h"

UCLASS(Blueprintable)
class UAstroColorDatabase : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAstroColor, FLinearColor> ColorDatabase;
    
    UAstroColorDatabase();
};

