// Fill out your copyright notice in the Description page of Project Settings.


#include "EQC_TaggedActors.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "EngineUtils.h"

void UEQC_TaggedActors::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
    UWorld* World = QueryInstance.World;
    APawn* Querier = Cast<APawn>(QueryInstance.Owner.Get());

    if (!World || ActorTag.IsNone()) return;

    TArray<AActor*> MatchingActors;

    const FVector QuerierLoc = Querier ? Querier->GetActorLocation() : FVector::ZeroVector;
    const float RadiusSq = MaxSearchRadius * MaxSearchRadius;

    for (TActorIterator<AActor> It(World); It; ++It)
    {
        AActor* Actor = *It;
        if (!Actor || Actor == Querier) continue;

        if (!Actor->ActorHasTag(ActorTag)) continue;

        if (Querier && MaxSearchRadius > 0.f)
        {
            if (FVector::DistSquared(QuerierLoc, Actor->GetActorLocation()) > RadiusSq) continue;
        }

        MatchingActors.Add(Actor);
    }

    UEnvQueryItemType_Actor::SetContextHelper(ContextData, MatchingActors);
}
