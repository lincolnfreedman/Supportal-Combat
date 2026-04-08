// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQCs/EQC_PlayerAllies.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EngineUtils.h"

void UEQC_PlayerAllies::ProvideContext(
    FEnvQueryInstance& QueryInstance,
    FEnvQueryContextData& ContextData) const
{
    APawn* Querier = Cast<APawn>(QueryInstance.Owner.Get());
    if (!Querier) return;

    UWorld* World = QueryInstance.World;
    if (!World) return;

    TArray<AActor*> Results;
    const FVector QuerierLoc = Querier->GetActorLocation();
    const float RadiusSq = MaxSearchRadius * MaxSearchRadius;

    //for player from bb
    AAIController* AIC = Cast<AAIController>(Querier->GetController());
    if (AIC)
    {
        UBlackboardComponent* BB = AIC->GetBlackboardComponent();
        if (BB)
        {
            AActor* Player = Cast<AActor>(
                BB->GetValueAsObject(PlayerBlackboardKey));
            if (Player && FVector::DistSquared(
                QuerierLoc, Player->GetActorLocation()) <= RadiusSq)
            {
                Results.Add(Player);
            }
        }
    }

    // for allies using tag
    for (TActorIterator<AActor> It(World); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor || Actor == Querier) continue;
        if (!Actor->ActorHasTag(AllyTag)) continue;

        if (FVector::DistSquared(QuerierLoc, Actor->GetActorLocation())
            <= RadiusSq)
        {
            Results.Add(Actor);
        }
    }

    UEnvQueryItemType_Actor::SetContextHelper(ContextData, Results);
}
