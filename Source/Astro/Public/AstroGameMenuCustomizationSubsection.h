#pragma once
#include "CoreMinimal.h"
//#include "AstroCharacterHatDisplayOption.h"
//#include "AstroCharacterPaletteDisplayOption.h"
//#include "AstroSuitDisplayOption.h"
//#include "AstroVisorMaterialDisplayOption.h"
#include "AstroCharacterCustomization.h"
#include "UserWidgetBlueprintDesignable.h"
#include "AstroGameMenuCustomizationSubsection.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UAstroGameMenuCustomizationSubsection : public UUserWidgetBlueprintDesignable {
    GENERATED_BODY()
public:
protected:
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroSuitDisplayOption> AvailableSuits;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroVisorMaterialDisplayOption> AvailableVisors;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroCharacterPaletteDisplayOption> AvailablePalettes;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroCharacterHatDisplayOption> AvailableHats;
    
//    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
//    TArray<FAstroCharacterHatDisplayOption> AvailableMasks;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAstroCharacterCustomization CurrentlyCommittedCharacterCustomizationOptions;
    
public:
    UAstroGameMenuCustomizationSubsection();

protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateVisorSelectionOption(int32 Index);
    
    UFUNCTION(BlueprintCallable)
    void UpdateUnlockSelectionsFromPlayfabData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateSuitSelectionOption(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdatePaletteSelectionOption(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateMaskSelectionOption(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHatSelectionOption(int32 Index);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateEmoteSlots(bool WithLayout);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetupEmoteSlots();
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentlyCommittedCharacterCustomizationOptions(const FAstroCharacterCustomization& CharacterCustomization);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSubsectionClosed();
    
public:
    UFUNCTION(BlueprintCallable)
    void NotifySubsectionClosed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MakeVisorSelectionOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MakeSuitSelectionOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MakePaletteSelectionOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MakeMaskSelectionOptions();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MakeHatSelectionOptions();
    
};

