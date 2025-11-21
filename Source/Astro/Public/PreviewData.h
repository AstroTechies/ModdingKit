#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SlotReference.h"
#include "Templates/SubclassOf.h"
#include "PreviewData.generated.h"

class APhysicalItem;
class UItemType;
class UMaterialInterface;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FPreviewData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> PreviewItemType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoxSphereBounds BoundingBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APhysicalItem* PreviewPhysicalItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference PreviewSlotReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlotReference DefaultSlotReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* UnpackIndicatorRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInterface*> UnpackIndicatorRootOriginalMaterials;
    
    ASTRO_API FPreviewData();
};

