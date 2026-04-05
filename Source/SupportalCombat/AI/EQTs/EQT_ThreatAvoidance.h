// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_ThreatAvoidance.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Threat Avoidance (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_ThreatAvoidance : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
	UEQT_ThreatAvoidance();

	UPROPERTY(EditAnywhere, Category = "Threat")
	float DangerRadius = 1500.f;

	UPROPERTY(EditAnywhere, Category = "Threat")
	TSubclassOf<UEnvQueryContext> EnemyContext;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
	virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
	mutable TArray<FVector> CachedEnemyLocations;
};
