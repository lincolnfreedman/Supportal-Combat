// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_PlayerProximity.h"

UEQT_PlayerProximity::UEQT_PlayerProximity()
{
	BlackboardFloatKey = TEXT("HealthUrgency");
	bInvertKeyValue = true;
	MinWeightMultiplier = 0.05f;
}

void UEQT_PlayerProximity::RunTest(FEnvQueryInstance& QueryInstance) const
{
	bPlayerValid = false;

	if (PlayerContext)
	{
		TArray<FVector> Locations;
		QueryInstance.PrepareContext(*PlayerContext, Locations);
		
		if (Locations.Num() > 0)
		{
			CachedPlayerLocation = Locations[0];
			bPlayerValid = true;
		}
	}

	if (!bPlayerValid) return;
	
	Super::RunTest(QueryInstance);
}

float UEQT_PlayerProximity::ScoreItem(const FVector& ItemLocation) const
{
	if (!bPlayerValid) return 0.f;
	const float Dist = FVector::Dist(ItemLocation, CachedPlayerLocation);

	if (Dist > MaxDistance) return 0.f;

	const float Deviation = FMath::Abs(Dist - IdealDistance);
	const float NormDev = Deviation / MaxDistance;
	return FMath::Clamp(1.0f - (NormDev*NormDev), 0.f, 1.f);
}