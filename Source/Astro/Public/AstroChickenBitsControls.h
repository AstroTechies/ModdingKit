#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AstroChickenBitsControls.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UAstroChickenBitsControls : public UObject
{
    GENERATED_BODY()
public:
    UAstroChickenBitsControls();
    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Vehicles_ShowDrillDebugVis();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Vehicles_ApplyDrillDeformations();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Vehicles_AllowConstraintConnections();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Menu_AlwaysPlayIntroCutscene();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Menu_AllowSaveFileRenaming();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Menu_AllowSaveFileDuplication();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Controls_UseItemMoveTierRestrictions();

    UFUNCTION(BlueprintPure)
    static int32 GetCvar_Controls_UseActiveGrab();
};
