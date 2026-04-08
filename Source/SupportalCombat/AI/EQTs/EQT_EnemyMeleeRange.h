// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/EQTs/EQT_DynamicWeight.h"
#include "GameplayTagContainer.h"
#include "EQT_EnemyMeleeRange.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Enemy Melee Range (Dynamic)"))
class SUPPORTALCOMBAT_API UEQT_EnemyMeleeRange : public UEQT_DynamicWeight
{
	GENERATED_BODY()
	
public: UEQT_EnemyMeleeRange();

      UPROPERTY(EditAnywhere, Category = "Melee")
      float MeleeRange = 250.f;

      UPROPERTY(EditAnywhere, Category = "Melee")
      float MaxApproachDistance = 1500.f;

      UPROPERTY(EditAnywhere, Category = "Melee",
          meta = (ClampMin = "1.0", ClampMax = "3.0"))
      float StunnedBonusMultiplier = 2.0f;

      UPROPERTY(EditAnywhere, Category = "Melee")
      FGameplayTag StunnedTag;

      UPROPERTY(EditAnywhere, Category = "Melee")
      TSubclassOf<UEnvQueryContext> EnemyContext;

      virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;
      virtual float ScoreItem(const FVector& ItemLocation) const override;

private:
    struct FEnemyInfo
    {
        FVector Location;
        bool bIsStunned;
    };

    mutable TArray<FEnemyInfo> CachedEnemies;
};
