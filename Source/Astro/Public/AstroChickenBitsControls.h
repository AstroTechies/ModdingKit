#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroChickenBitsControls.generated.h"

UCLASS(Blueprintable)
class UAstroChickenBitsControls : public UObject {
    GENERATED_BODY()
public:
    UAstroChickenBitsControls();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Vehicles_ShowDrillDebugVis();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Vehicles_ApplyDrillDeformations();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Vehicles_AllowConstraintConnections();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Menu_AlwaysPlayIntroCutscene();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Menu_AllowSaveFileRenaming();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Menu_AllowSaveFileDuplication();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Controls_UseItemMoveTierRestrictions();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCvar_Controls_UseActiveGrab();
    
};

