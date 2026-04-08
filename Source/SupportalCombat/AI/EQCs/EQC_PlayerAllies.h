// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EQC_PlayerAllies.generated.h"

/**
 * 
 */
UCLASS()
class SUPPORTALCOMBAT_API UEQC_PlayerAllies : public UEnvQueryContext
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Category = "Context")
    FName PlayerBlackboardKey = TEXT("PlayerActor");

    UPROPERTY(EditAnywhere, Category = "Context")
    FName AllyTag = TEXT("Ally");

    UPROPERTY(EditAnywhere, Category = "Context")
    float MaxSearchRadius = 5000.f;

    virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
};
