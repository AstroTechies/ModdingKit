#pragma once
#include "CoreMinimal.h"
#include "FAstroCGMPlayfabFailureReason.generated.h"

UENUM(BlueprintType)
enum class FAstroCGMPlayfabFailureReason : uint8 {
    GetItemError,
    FailedConnection,
    JsonParseError,
    NoContent,
    GetSESPromotedItemsError,
    GetPlayerSavedPublishedConfigsMetaDataError,
    GetPlayerImportedConfigsMetaDataError,
    UpdatePlayerSavedPublishedConfigsMetaDataError,
    UpdatePlayerImportedConfigsMetaDataError,
    CreateUploadURLsError,
    GetNextCGMConfigShareCodeError,
    CreateDraftUGCItemError,
    UGCDisabledError,
    ContentAlreadyImported,
    Generic,
    Count,
};

