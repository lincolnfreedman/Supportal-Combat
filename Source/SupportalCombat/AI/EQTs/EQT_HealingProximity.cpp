// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_HealingProximity.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EnvironmentQuery/EnvQueryTypes.h"

UEQT_HealingProximity::UEQT_HealingProximity()
{
	BlackboardFloatKey = TEXT("HealthUrgency");
	bInvertKeyValue = false;
	MinWeightMultiplier = 0.0f;
}

void UEQT_HealingProximity::RunTest(FEnvQueryInstance& QueryInstance) const
{
	CachedHealingLocations.Reset();

	if (HealingContext)
	{
		TArray<FVector> ContextLocations;
		QueryInstance.PrepareContext(*HealingContext, ContextLocations);
		CachedHealingLocations = MoveTemp(ContextLocations);
	}

	if (CachedHealingLocations.Num() == 0) return;

	Super::RunTest(QueryInstance);
}

float UEQT_HealingProximity::ScoreItem(const FVector& ItemLocation) const
{
	float ClosestDist = MaxRange;

	for (const FVector& HealLoc : CachedHealingLocations)
	{
		const float Dist = FVector::Dist(ItemLocation, HealLoc);
		ClosestDist = FMath::Min(ClosestDist, Dist);
	}

	return 1.0f - FMath::Clamp(ClosestDist / MaxRange, 0.f, 1.f);
}