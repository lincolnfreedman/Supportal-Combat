// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EQT_TargetWeakness.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Target Weakness (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_TargetWeakness : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public:
    UEQT_TargetWeakness();

    UPROPERTY(EditAnywhere, Category = "TargetWeakness")
    float MaxRange = 2500.f;

    // 0 = pure proximity
    // 1 = HP influences score
    UPROPERTY(EditAnywhere, Category = "TargetWeakness",
        meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float WeaknessInfluence = 0.7f;

    UPROPERTY(EditAnywhere, Category = "TargetWeakness")
    TSubclassOf<UEnvQueryContext> TargetContext;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
    virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
    struct FTargetInfo
    {
        FVector Location;
        float HealthFraction;
    };

    mutable TArray<FTargetInfo> CachedTargets;
};