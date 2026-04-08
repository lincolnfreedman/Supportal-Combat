// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_LOSAvoidance.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "LOS Avoidance (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_LOSAvoidance : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
    UEQT_LOSAvoidance();

    UPROPERTY(EditAnywhere, Category = "LOS")
    float TraceHeightOffset = 90.f;

    UPROPERTY(EditAnywhere, Category = "LOS")
    TSubclassOf<UEnvQueryContext> ThreatContext;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
    virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
    mutable TArray<FVector> CachedThreatLocations;
    mutable UWorld* CachedWorld = nullptr;
};
