#pragma once
#include "CoreMinimal.h"
#include "ECrackableActorNetworkingPolicy.generated.h"

UENUM()
enum class ECrackableActorNetworkingPolicy : uint8 {
    LocalOnlyNoNetworking,
    OwnerOnlyWithNetworking,
    AnyoneSingleUserWithNetworking,
};

