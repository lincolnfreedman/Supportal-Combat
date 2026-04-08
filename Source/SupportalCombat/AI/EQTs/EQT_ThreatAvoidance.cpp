// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_ThreatAvoidance.h"

UEQT_ThreatAvoidance::UEQT_ThreatAvoidance()
{
	BlackboardFloatKey = TEXT("HealthUrgency");
	bInvertKeyValue = false;
	MinWeightMultiplier = 0.15f;
}

void UEQT_ThreatAvoidance::RunTest(FEnvQueryInstance& QueryInstance) const
{
	CachedEnemyLocations.Reset();

	if (EnemyContext)
	{
		TArray<FVector> Locations;
		QueryInstance.PrepareContext(*EnemyContext, Locations);
		CachedEnemyLocations = MoveTemp(Locations);
	}

	if (CachedEnemyLocations.Num() == 0) return;

	Super::RunTest(QueryInstance);
}

float UEQT_ThreatAvoidance::ScoreItem(const FVector& ItemLocation) const
{
	float CumulativeThreat = 0.f;

	for (const FVector& EnemyLoc : CachedEnemyLocations)
	{
		const float Dist = FVector::Dist(ItemLocation, EnemyLoc);

		if (Dist < DangerRadius)
		{
			CumulativeThreat += 1.f - (Dist / DangerRadius);
		}
	}

	return FMath::Clamp(1.0f - CumulativeThreat, 0.f, 1.f);
}