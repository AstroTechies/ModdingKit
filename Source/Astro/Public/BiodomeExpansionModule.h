#pragma once
#include "CoreMinimal.h"
#include "BiodomeModule.h"
#include "BiodomeSection.h"
#include "SlotReference.h"
#include "BiodomeExpansionModule.generated.h"

UCLASS(Blueprintable)
class ASTRO_API ABiodomeExpansionModule : public ABiodomeModule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlotReference> SeedSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCanPlace: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBiodomeSection BiodomeSection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsLocked, meta=(AllowPrivateAccess=true))
    bool bIsLocked;
    
public:
    ABiodomeExpansionModule(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void SetCanPlace(bool newCanPlace);
    
    UFUNCTION(BlueprintCallable)
    void SetBiodomeSection(FBiodomeSection newBiodomeSection);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_IsLocked();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AuthorityToggleLock();
    
};

