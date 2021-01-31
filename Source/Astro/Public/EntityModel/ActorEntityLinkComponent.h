// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActorEntityLinkComponent.generated.h"

USTRUCT(BlueprintType)
struct ASTRO_API FAstroDatumRef
{
	GENERATED_USTRUCT_BODY()

public:

};

UCLASS(BlueprintType)
class ASTRO_API UAstroDatumContainer : public UObject
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class ASTRO_API UAstroEntityComponentContainer : public UAstroDatumContainer
{
	GENERATED_BODY()

};

class UAstroEntityComponentSubobjectDefinition;

UCLASS(BlueprintType)
class ASTRO_API UAstroEntityComponentSubobject : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAstroDatumRef OwnerComponentRef;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName DefinitionName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAstroEntityComponentSubobjectDefinition* Definition;
};

UENUM()
enum class EAstroEntityComponentSubobjectTickGroup : uint8 {
	PrePhysics = 0,
	PostPhysics = 1
};

UCLASS(BlueprintType)
class ASTRO_API UAstroEntityComponentSubobjectDefinition : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAstroEntityComponentSubobject> RuntimeSubobjectType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAstroEntityComponentSubobjectTickGroup TickGroup;
};

USTRUCT(BlueprintType)
struct ASTRO_API FNamedEntityComponentDefinition
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UAstroEntityComponentContainer> ComponentType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LinkedActorComponentName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<UAstroEntityComponentSubobjectDefinition *> ComponentSubobjectDefinitions;
};

USTRUCT(BlueprintType)
struct ASTRO_API FAstroEntityDefinition
{
	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FNamedEntityComponentDefinition> Components;
};

UCLASS(EditInlineNew, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ASTRO_API UActorEntityLinkComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorEntityLinkComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAstroEntityDefinition EntityDefinition;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAstroDatumRef EntityRef;
	
};
