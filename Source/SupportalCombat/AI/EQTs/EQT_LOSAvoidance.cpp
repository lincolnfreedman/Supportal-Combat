// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_LOSAvoidance.h"
#include "CollisionQueryParams.h"
#include "Engine/World.h"

UEQT_LOSAvoidance::UEQT_LOSAvoidance()
{
    BlackboardFloatKey = TEXT("HealthUrgency");
    bInvertKeyValue = false;  
    MinWeightMultiplier = 0.0f;
    Cost = EEnvTestCost::High;
}

void UEQT_LOSAvoidance::RunTest(FEnvQueryInstance& QueryInstance) const
{
    CachedThreatLocations.Reset();
    CachedWorld = QueryInstance.World;

    if (!ThreatContext || !CachedWorld) return;

    TArray<FVector> Locations;
    QueryInstance.PrepareContext(*ThreatContext, Locations);

    for (FVector& Loc : Locations)
    {
        Loc.Z += TraceHeightOffset;
    }

    CachedThreatLocations = MoveTemp(Locations);
    if (CachedThreatLocations.Num() == 0) return;

    Super::RunTest(QueryInstance);
}

float UEQT_LOSAvoidance::ScoreItem(const FVector& ItemLocation) const
{
    if (!CachedWorld || CachedThreatLocations.Num() == 0) return 0.f;

    int32 HiddenFromCount = 0;
    const FVector EyePos = ItemLocation + FVector(0.f, 0.f, TraceHeightOffset);

    FCollisionQueryParams TraceParams;
    TraceParams.bTraceComplex = false;

    for (const FVector& ThreatLoc : CachedThreatLocations)
    {
        FHitResult Hit;
        const bool bHit = CachedWorld->LineTraceSingleByChannel(Hit,ThreatLoc,EyePos,ECC_Visibility,TraceParams);

        if (bHit)HiddenFromCount++;
    }

    return static_cast<float>(HiddenFromCount) / static_cast<float>(CachedThreatLocations.Num());
}
