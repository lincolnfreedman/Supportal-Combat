// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EQC_Player.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Player (from Blackboard)"))
class SUPPORTALCOMBAT_API UEQC_Player : public UEnvQueryContext
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Context")
	FName PlayerBlackboardKey = TEXT("PlayerActor");

	virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
