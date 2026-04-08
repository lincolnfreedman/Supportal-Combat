// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_SmokeProximity.h"

UEQT_SmokeProximity::UEQT_SmokeProximity()
{
    BlackboardFloatKey = TEXT("HealthUrgency");
    bInvertKeyValue = false;
    MinWeightMultiplier = 0.0f;
}

void UEQT_SmokeProximity::RunTest(FEnvQueryInstance& QueryInstance) const
{
    CachedSmokeLocations.Reset();

    if (!SmokeContext) return;

    TArray<FVector> Locations;
    QueryInstance.PrepareContext(*SmokeContext, Locations);
    CachedSmokeLocations = MoveTemp(Locations);

    if (CachedSmokeLocations.Num() == 0) return;

    Super::RunTest(QueryInstance);
}

float UEQT_SmokeProximity::ScoreItem(const FVector& ItemLocation) const
{
    float BestScore = 0.f;

    for (const FVector& SmokeLoc : CachedSmokeLocations)
    {
        const float Dist = FVector::Dist(ItemLocation, SmokeLoc);

        if (Dist <= SmokeRadius)
        {
            BestScore = 1.f;
            break;
        }
        else if (Dist <= MaxRange)
        {
            const float EdgeDist = Dist - SmokeRadius;
            const float Falloff = MaxRange - SmokeRadius;
            const float Score = 1.0f - FMath::Clamp(EdgeDist / Falloff, 0.f, 1.f);
            BestScore = FMath::Max(BestScore, Score);
        }
    }

    return BestScore;
}