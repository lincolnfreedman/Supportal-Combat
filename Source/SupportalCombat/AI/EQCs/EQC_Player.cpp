// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EQCs/EQC_Player.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"

void UEQC_Player::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	APawn* Querier = Cast<APawn>(QueryInstance.Owner.Get());
	if (!Querier) return;
	
	AAIController* AIC = Cast<AAIController>(Querier->GetController());
	if (!AIC) return;

	UBlackboardComponent* BB = AIC->GetBlackboardComponent();
	if (!BB) return;

	AActor* Player = Cast<AActor>(BB->GetValueAsObject(PlayerBlackboardKey));
	if (!Player) return;
	
	TArray<const AActor*> PlayerArray;
	PlayerArray.Add(Player);
	UEnvQueryItemType_Actor::SetContextHelper(ContextData, PlayerArray);
}