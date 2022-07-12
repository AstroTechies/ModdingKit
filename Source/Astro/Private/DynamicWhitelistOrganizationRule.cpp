#include "DynamicWhitelistOrganizationRule.h"
#include "Templates/SubclassOf.h"

class UItemType;

void UDynamicWhitelistOrganizationRule::SetWhitelist(const TArray<TSubclassOf<UItemType>>& Whitelist) {
}

void UDynamicWhitelistOrganizationRule::SetShowIndicators(bool showIndicators) {
}

void UDynamicWhitelistOrganizationRule::SetRequireNonFullItems(bool requireNonFullItems) {
}

UDynamicWhitelistOrganizationRule::UDynamicWhitelistOrganizationRule() {
    this->bShowIndicators = true;
}

