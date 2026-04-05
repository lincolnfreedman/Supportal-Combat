// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_AllyProximity.generated.h"

/**
 * 
 */
UCLASS()
class SUPPORTALCOMBAT_API UEQT_AllyProximity : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
	UEQT_AllyProximity();

	UPROPERTY(EditAnywhere, Category = "Ally")
	float IdealAllyDistance = 400.f;

	UPROPERTY(EditAnywhere, Category = "Ally")
	float MaxAllyDistance = 1500.f;

	UPROPERTY(EditAnywhere, Category = "Ally")
	TSubclassOf<UEnvQueryContext> AllyContext;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
	virtual float ScoreItem(const FVector& ItemLocation) const override;
	
private:
	mutable TArray<FVector> CachedAllyLocations;
};
