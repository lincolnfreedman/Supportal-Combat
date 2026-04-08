// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_KeepDistance.h"

UEQT_KeepDistance::UEQT_KeepDistance()
{
    BlackboardFloatKey = TEXT("HealthUrgency");
    bInvertKeyValue = true;
    MinWeightMultiplier = 0.1f;
}

void UEQT_KeepDistance::RunTest(FEnvQueryInstance& QueryInstance) const
{
    CachedTargetLocations.Reset();

    if (!TargetContext) return;

    TArray<FVector> Locations;
    QueryInstance.PrepareContext(*TargetContext, Locations);
    CachedTargetLocations = MoveTemp(Locations);

    if (CachedTargetLocations.Num() == 0) return;

    Super::RunTest(QueryInstance);
}

float UEQT_KeepDistance::ScoreItem(const FVector& ItemLocation) const
{
    float WorstScore = 1.f;

    for (const FVector& TargetLoc : CachedTargetLocations)
    {
        const float Dist = FVector::Dist(ItemLocation, TargetLoc);
        float Score;

        if (Dist >= MinIdealDistance && Dist <= MaxIdealDistance)
        {
            Score = 1.f;
        }
        else if (Dist < MinIdealDistance)
        {
            Score = FMath::Clamp(Dist / MinIdealDistance, 0.f, 1.f);
        }
        else if (Dist <= MaxRelevantDistance)
        {
            const float Over = Dist - MaxIdealDistance;
            const float Falloff = MaxRelevantDistance - MaxIdealDistance;
            Score = 1.0f - FMath::Clamp(Over / Falloff, 0.f, 1.f);
        }
        else
        {
            Score = 0.f;
        }

        WorstScore = FMath::Min(WorstScore, Score);
    }

    return WorstScore;
}