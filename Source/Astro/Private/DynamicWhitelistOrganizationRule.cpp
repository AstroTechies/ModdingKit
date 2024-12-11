#include "DynamicWhitelistOrganizationRule.h"
#include "Templates/SubclassOf.h"

UDynamicWhitelistOrganizationRule::UDynamicWhitelistOrganizationRule() {
    this->bEjectUnwantedItems = true;
    this->bRequireLiteralItemType = false;
}

void UDynamicWhitelistOrganizationRule::SetWhitelist(const TArray<TSubclassOf<UItemType>>& Whitelist) {
}

void UDynamicWhitelistOrganizationRule::SetShowIndicators(bool showIndicators) {
}

void UDynamicWhitelistOrganizationRule::SetRequireNonFullItems(bool requireNonFullItems) {
}

void UDynamicWhitelistOrganizationRule::SetRequireLiteralItemType(bool requireLiteralItemType) {
}


