// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQTs/EQT_EnemyMeleeRange.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

UEQT_EnemyMeleeRange::UEQT_EnemyMeleeRange()
{
	BlackboardFloatKey = TEXT("HealthUrgency");
	bInvertKeyValue = true;
	MinWeightMultiplier = 0.0f;
}

void UEQT_EnemyMeleeRange::RunTest(FEnvQueryInstance& QueryInstance) const
{
    CachedEnemies.Reset();

    if (!EnemyContext) return;

    TArray<AActor*> ContextActors;
    QueryInstance.PrepareContext(*EnemyContext, ContextActors);

    for (AActor* Actor : ContextActors)
    {
        if (!Actor) continue;

        FEnemyInfo Info;
        Info.Location = Actor->GetActorLocation();

        Info.bIsStunned = false;
		UAbilitySystemComponent* ASC = UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor);
        if (ASC) 
        {
			Info.bIsStunned = ASC->HasMatchingGameplayTag(StunnedTag);
        }

        CachedEnemies.Add(Info);
    }

    if (CachedEnemies.Num() == 0) return;

    Super::RunTest(QueryInstance);
}

float UEQT_EnemyMeleeRange::ScoreItem(const FVector& ItemLocation) const
{
    float BestScore = 0.f;

    for (const FEnemyInfo& Enemy : CachedEnemies)
    {
        const float Dist = FVector::Dist(ItemLocation, Enemy.Location);
        if (Dist > MaxApproachDistance) continue;

        float Score;

        if (Dist <= MeleeRange) Score = 1.f;
        else
        {
            const float Over = Dist - MeleeRange;
            const float Falloff = MaxApproachDistance - MeleeRange;
            Score = 1.0f - FMath::Clamp(Over / Falloff, 0.f, 1.f);
        }

        if (Enemy.bIsStunned)
        {
            Score *= StunnedBonusMultiplier;
        }

        BestScore = FMath::Max(BestScore, Score);
    }

    return FMath::Clamp(BestScore / StunnedBonusMultiplier, 0.f, 1.f);
}