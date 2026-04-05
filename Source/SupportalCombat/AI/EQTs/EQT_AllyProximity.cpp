// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_AllyProximity.h"

UEQT_AllyProximity::UEQT_AllyProximity()
{
	BlackboardFloatKey = TEXT("HealthUrgency");
	bInvertKeyValue = true;
	MinWeightMultiplier = 0.0f;
}

void UEQT_AllyProximity::RunTest(FEnvQueryInstance& QueryInstance) const
{
	CachedAllyLocations.Reset();

	if (AllyContext)
	{
		TArray<FVector> Locations;
		QueryInstance.PrepareContext(*AllyContext, Locations);
		CachedAllyLocations = MoveTemp(Locations);
	}

	if (CachedAllyLocations.Num() == 0) return;

	Super::RunTest(QueryInstance);
}

float UEQT_AllyProximity::ScoreItem(const FVector& ItemLocation) const
{
	float BestScore = 0.f;

	for (const FVector& AllyLoc : CachedAllyLocations) 
	{
		const float Dist = FVector::Dist(ItemLocation, AllyLoc);
		if (Dist > MaxAllyDistance) continue;

		const float Deviation = FMath::Abs(Dist - IdealAllyDistance);
		const float NormDev = Deviation / MaxAllyDistance;
		const float Score = FMath::Clamp(1.f - (NormDev * NormDev), 0.f, 1.f);

		BestScore = FMath::Max(BestScore, Score);
	}

	return BestScore;
}