#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroDatumRef.h"
#include "AstroEntityWorld.generated.h"

class UAstroSaveCustomArchiveProxy;
class UAstroEntityComponentSubobject;
class UAstroEntityTaskManager;
class UAstroEntityContainer;
class UAstroEntityComponentContainer;
class UAstroEntitySystem;

UCLASS(Blueprintable, BlueprintType)
class ASTRO_API UAstroEntityWorld : public UObject
{
    GENERATED_BODY()
public:
private:
    UPROPERTY(SaveGame)
    UAstroEntityContainer *EntityContainer;

    UPROPERTY(SaveGame)
    TArray<UAstroEntityComponentContainer *> EntityComponentContainers;

    UPROPERTY()
    TArray<UAstroEntitySystem *> Systems;

    UPROPERTY(SaveGame)
    TArray<UAstroEntityComponentSubobject *> PrePhysicsTickingEntityComponentSubobjects;

    UPROPERTY(SaveGame)
    TArray<UAstroEntityComponentSubobject *> PostPhysicsTickingEntityComponentSubobjects;

    UPROPERTY(Transient)
    TArray<UAstroEntityComponentSubobject *> EntityComponentSubobjectsPendingTickDeactivation;

    UPROPERTY(Transient)
    TArray<UAstroEntityTaskManager *> EntityTaskManagers;

public:
    UAstroEntityWorld();

private:
    UFUNCTION()
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy *proxy);

public:
    UFUNCTION(BlueprintPure)
    static FAstroDatumRef GetOwnerEntity(FAstroDatumRef EntityComponentRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FAstroDatumRef GetEntityRootComponentRef(FAstroDatumRef EntityRef, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static FAstroDatumRef GetEntityComponentRefByName(FAstroDatumRef EntityRef, FName ComponentName, bool &bOutSuccess);

    UFUNCTION(BlueprintPure)
    static TArray<FAstroDatumRef> GetEntityComponentDatumRefs(FAstroDatumRef EntityRef, bool &bOutSuccess);
};
