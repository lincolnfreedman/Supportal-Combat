// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EQT_DynamicWeight.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class SUPPORTALCOMBAT_API UEQT_DynamicWeight : public UEnvQueryTest
{
	GENERATED_BODY()
	
public:
	UEQT_DynamicWeight();

	UPROPERTY(EditAnywhere, Category = "DynamicWeight")
	FName BlackboardFloatKey;

	UPROPERTY(EditAnywhere, Category = "DynamicWeight")
	bool bInvertKeyValue = false;

	UPROPERTY(EditAnywhere, Category = "DynamicWeight", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MinWeightMultiplier = 0.0f;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual float ScoreItem(const FVector& ItemLocation) const PURE_VIRTUAL(UEQT_DynamicWeight::ScoreItem, return 0.f;);

protected:
	float GetDynamicMultiplier(FEnvQueryInstance& QueryInstance) const;
	UBlackboardComponent* GetQuerierBlackboard(FEnvQueryInstance& QueryInstance) const;
};
