// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_KeepDistance.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Keep Distance (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_KeepDistance : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
    UEQT_KeepDistance();

    UPROPERTY(EditAnywhere, Category = "Distance")
    float MinIdealDistance = 800.f;

    UPROPERTY(EditAnywhere, Category = "Distance")
    float MaxIdealDistance = 1500.f;

    UPROPERTY(EditAnywhere, Category = "Distance")
    float MaxRelevantDistance = 3000.f;

    UPROPERTY(EditAnywhere, Category = "Distance")
    TSubclassOf<UEnvQueryContext> TargetContext;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
    virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
    mutable TArray<FVector> CachedTargetLocations;
};
