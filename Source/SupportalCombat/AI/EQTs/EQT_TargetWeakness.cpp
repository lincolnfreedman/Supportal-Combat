// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_TargetWeakness.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "SupportalCombat/GasAttributeSets/BasicAttributeSet.h"

UEQT_TargetWeakness::UEQT_TargetWeakness()
{
    BlackboardFloatKey = TEXT("HealthUrgency");
    bInvertKeyValue = true;
    MinWeightMultiplier = 0.0f;
}

void UEQT_TargetWeakness::RunTest(
    FEnvQueryInstance& QueryInstance) const
{
    CachedTargets.Reset();

    if (!TargetContext) return;

    TArray<AActor*> ContextActors;
    QueryInstance.PrepareContext(*TargetContext, ContextActors);

    for (AActor* Actor : ContextActors)
    {
        if (!Actor) continue;

        float HPFrac = 1.f;
        UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
        if (ASC)
        {
            bool bFound = false;

			float CurHP = ASC->GetNumericAttribute(UBasicAttributeSet::GetHealthAttribute());
            float MaxHP = ASC->GetNumericAttribute(UBasicAttributeSet::GetMaxHealthAttribute());

            if (MaxHP > 0.f) HPFrac = CurHP / MaxHP;
        }

        FTargetInfo Info;
        Info.Location = Actor->GetActorLocation();
        Info.HealthFraction = FMath::Clamp(HPFrac, 0.f, 1.f);
        CachedTargets.Add(Info);
    }

    if (CachedTargets.Num() == 0) return;

    Super::RunTest(QueryInstance);
}

float UEQT_TargetWeakness::ScoreItem(const FVector& ItemLocation) const
{
    float BestScore = 0.f;

    for (const FTargetInfo& Target : CachedTargets)
    {
        const float Dist = FVector::Dist(ItemLocation, Target.Location);
        if (Dist > MaxRange) continue;

        const float ProximityScore = 1.0f - FMath::Clamp(Dist / MaxRange, 0.f, 1.f);

        const float WeaknessScore = 1.0f - Target.HealthFraction;

        const float Combined = FMath::Lerp(ProximityScore,ProximityScore * (0.3f + 0.7f * WeaknessScore),WeaknessInfluence);

        BestScore = FMath::Max(BestScore, Combined);
    }

    return BestScore;
}