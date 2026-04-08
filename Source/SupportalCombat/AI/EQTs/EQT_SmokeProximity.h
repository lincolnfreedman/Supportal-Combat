// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_SmokeProximity.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Smoke Proximity (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_SmokeProximity : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
    UEQT_SmokeProximity();

    UPROPERTY(EditAnywhere, Category = "Smoke")
    float SmokeRadius = 500.f; //todo-match the smoke effect actor radius

    UPROPERTY(EditAnywhere, Category = "Smoke")
    float MaxRange = 2000.f;

    UPROPERTY(EditAnywhere, Category = "Smoke")
    TSubclassOf<UEnvQueryContext> SmokeContext;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
    virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
    mutable TArray<FVector> CachedSmokeLocations;
};