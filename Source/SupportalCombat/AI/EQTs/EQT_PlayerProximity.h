// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_PlayerProximity.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Player Proximity (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_PlayerProximity : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
	UEQT_PlayerProximity();

	UPROPERTY(EditAnywhere, Category = "Proximity")
	float IdealDistance = 500.f;

	UPROPERTY(EditAnywhere, Category = "Proximity")
	float MaxDistance = 2000.f;

	UPROPERTY(EditAnywhere, Category = "Proximity")
	TSubclassOf<UEnvQueryContext> PlayerContext;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
	virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
	mutable FVector CachedPlayerLocation;
	mutable bool bPlayerValid = false;
};
