#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MuseumMilestone.h"
#include "MuseumSinkMilestones.generated.h"

UCLASS(Blueprintable)
class UMuseumSinkMilestones : public UDataAsset {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMuseumMilestone> Milestones;
    
public:
    UMuseumSinkMilestones();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidMilestoneIndex(const uint8 inIndex) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    uint8 GetNumberOfMilestones() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FMuseumMilestone GetMilestoneAtIndex(const uint8 inIndex) const;
    
};

