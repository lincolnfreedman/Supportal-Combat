// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_DynamicWeight.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UEQT_DynamicWeight::UEQT_DynamicWeight()
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
}

UBlackboardComponent* UEQT_DynamicWeight::GetQuerierBlackboard(FEnvQueryInstance& QueryInstance) const
{
	APawn* Querier = Cast<APawn>(QueryInstance.Owner.Get());
	if (!Querier) return nullptr;

	AAIController* AIC= Cast<AAIController>(Querier->GetController());
	return AIC ? AIC->GetBlackboardComponent() : nullptr;
}

float UEQT_DynamicWeight::GetDynamicMultiplier(FEnvQueryInstance& QueryInstance) const
{
	UBlackboardComponent* BB = GetQuerierBlackboard(QueryInstance);
	if (!BB) return MinWeightMultiplier;
	float Value = BB->GetValueAsFloat(BlackboardFloatKey);
	if (bInvertKeyValue) Value = 1.0f - Value;

	return FMath::Max(MinWeightMultiplier, FMath::Clamp(Value, 0.f, 1.f));
}

void UEQT_DynamicWeight::RunTest(FEnvQueryInstance& QueryInstance) const
{
	const float Multiplier = GetDynamicMultiplier(const_cast<FEnvQueryInstance&>(QueryInstance));
	
	if (Multiplier < KINDA_SMALL_NUMBER) return;

	for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It) 
	{
		const FVector ItemLoc = GetItemLocation(QueryInstance, It.GetIndex());
		const float RawScore = ScoreItem(ItemLoc);
		const float FinalScore = RawScore * Multiplier;
		It.SetScore(TestPurpose, FilterType, FinalScore, 0.f, 1.f);
	}
}