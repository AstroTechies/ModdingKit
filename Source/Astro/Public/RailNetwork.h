#pragma once
#include "CoreMinimal.h"
#include "MarkerStationList.h"
#include "DeformationParamsT2.h"
#include "GameFramework/Actor.h"
#include "RailConnectionLocalData.h"
#include "RailConnection.h"
#include "EStationMarkerType.h"
#include "RailNetwork.generated.h"

class UStaticMesh;
class UMaterialInterface;
class UClickableComponent;
class ASolarBody;
class USplineMeshComponent;
class UClickQuery;
class ARailPostStation;

UCLASS(Blueprintable, Blueprintable)
class ASTRO_API ARailNetwork : public AActor
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MaxRailAttachDistance;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = true))
    float MinRailAttachDistance;

    UPROPERTY(EditDefaultsOnly)
    float RailAttachMaxAngleDegrees;

    UPROPERTY(EditDefaultsOnly)
    float RailDeformVerticalOffset;

    UPROPERTY(EditDefaultsOnly)
    FDeformationParamsT2 RailDeformDefaultParams;

    UPROPERTY(EditDefaultsOnly)
    uint8 MaxCaravanLength;

    UPROPERTY(EditDefaultsOnly)
    UStaticMesh *RailMesh;

    UPROPERTY(EditDefaultsOnly)
    UMaterialInterface *ShortIndicatorMaterial;

    UPROPERTY(EditDefaultsOnly)
    float PercentageOfMaxDistanceToShowGoodIndicator;

protected:
    UPROPERTY(Export)
    UClickableComponent *clickable;

    UPROPERTY(SaveGame)
    int32 NextRailConnectionID;

    UPROPERTY(SaveGame, ReplicatedUsing = OnRep_RailConnections)
    TArray<FRailConnection> RailConnections;

    UPROPERTY(SaveGame)
    TMap<ASolarBody *, FMarkerStationList> StationMarkersByPlanet;

    UPROPERTY()
    TMap<int32, FRailConnectionLocalData> RailConnectionLocalData;

    UPROPERTY(Export)
    TArray<USplineMeshComponent *> RailConnectionMeshPool;

public:
    ARailNetwork();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty> &OutLifetimeProps) const override;

protected:
    UFUNCTION()
    void OnRep_RailConnections();

public:
    UFUNCTION()
    void HandleQueryClickable(UClickQuery *Query);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool AuthoritySetStationMarkerForPlanet(ARailPostStation *Station, ASolarBody *stationPlanet, EStationMarkerType marker);

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    ARailPostStation *AuthorityGetStationByMarker(ASolarBody *stationPlanet, EStationMarkerType currMarker) const;

    UFUNCTION(BlueprintAuthorityOnly, BlueprintPure)
    EStationMarkerType AuthorityGetNextAvailableStationMarkerForPlanet(ASolarBody *stationPlanet, EStationMarkerType currMarker, bool incrementSelection);
};
