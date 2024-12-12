#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroDatumRef.h"
#include "AstroEntityWorld.generated.h"

class UAstroEntityComponentContainer;
class UAstroEntityComponentSubobject;
class UAstroEntityContainer;
class UAstroEntitySystem;
class UAstroEntityTaskManager;
class UAstroSaveCustomArchiveProxy;

UCLASS(Blueprintable)
class ASTRO_API UAstroEntityWorld : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    UAstroEntityContainer* EntityContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentContainer*> EntityComponentContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntitySystem*> Systems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentSubobject*> PrePhysicsTickingEntityComponentSubobjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentSubobject*> PostPhysicsTickingEntityComponentSubobjects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityComponentSubobject*> EntityComponentSubobjectsPendingTickDeactivation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAstroEntityTaskManager*> EntityTaskManagers;
    
public:
    UAstroEntityWorld();

private:
    UFUNCTION(BlueprintCallable)
    void SaveGameSerializeCustom(UAstroSaveCustomArchiveProxy* proxy);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroDatumRef GetOwnerEntity(FAstroDatumRef EntityComponentRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroDatumRef GetEntityRootComponentRef(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FAstroDatumRef GetEntityComponentRefByName(FAstroDatumRef EntityRef, FName ComponentName, bool& bOutSuccess);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FAstroDatumRef> GetEntityComponentDatumRefs(FAstroDatumRef EntityRef, bool& bOutSuccess);
    
};

