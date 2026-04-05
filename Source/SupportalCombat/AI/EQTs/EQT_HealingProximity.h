// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_HealingProximity.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Healing Proximity (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_HealingProximity : public UEQT_DynamicWeight
{
	GENERATED_BODY()

public:
	UEQT_HealingProximity();

	UPROPERTY(EditAnywhere, Category = "Healing")
	float MaxRange = 3000.f;

	UPROPERTY(EditAnywhere, Category = "Healing")
	TSubclassOf<UEnvQueryContext> HealingContext;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
	virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
	mutable TArray<FVector> CachedHealingLocations;
};
