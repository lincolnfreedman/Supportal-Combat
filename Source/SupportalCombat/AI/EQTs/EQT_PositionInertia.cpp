// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_PositionInertia.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UEQT_PositionInertia::UEQT_PositionInertia()
{
    Cost = EEnvTestCost::Low;
    ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
}

void UEQT_PositionInertia::RunTest(
    FEnvQueryInstance& QueryInstance) const
{
    bHasValidDest = false;

    APawn* Querier = Cast<APawn>(QueryInstance.Owner.Get());
    if (!Querier) return;

    AAIController* AIC = Cast<AAIController>(Querier->GetController());
    if (!AIC) return;

    UBlackboardComponent* BB = AIC->GetBlackboardComponent();
    if (!BB) return;

    CachedCurrentDest = BB->GetValueAsVector(MoveToLocationKey);

    if (CachedCurrentDest.IsNearlyZero(1.f)) return;

    bHasValidDest = true;

    for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
    {
        const FVector ItemLoc = GetItemLocation(QueryInstance, It.GetIndex());
        const float Dist = FVector::Dist(ItemLoc, CachedCurrentDest);

        float Score;
        if (Dist <= InertiaRadius)
        {
            Score = 1.0f - FMath::Clamp(Dist / InertiaRadius, 0.f, 1.f);
        }
        else
        {
            Score = 0.f;
        }

        It.SetScore(TestPurpose, FilterType, Score, 0.f, 1.f);
    }
}
